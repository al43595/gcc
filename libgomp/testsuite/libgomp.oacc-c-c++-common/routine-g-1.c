/* { dg-additional-options "-Wopenacc-parallelism" } for testing/documenting
   aspects of that functionality.  */

#include <stdio.h>
#include <openacc.h>
#include <gomp-constants.h>

#define N (32*32*32+17)

#pragma acc routine gang
void __attribute__ ((noinline)) gang (int ary[N])
/* { dg-warning "region is worker partitioned but does not contain worker partitioned code" "" { target *-*-* } .-1 } */
/* { dg-warning "region is vector partitioned but does not contain vector partitioned code" "" { target *-*-* } .-2 } */
{
#pragma acc loop gang
    for (unsigned ix = 0; ix < N; ix++)
      {
	if (acc_on_device (acc_device_not_host))
	  {
	    int g, w, v;

	    g = __builtin_goacc_parlevel_id (GOMP_DIM_GANG);
	    w = __builtin_goacc_parlevel_id (GOMP_DIM_WORKER);
	    v = __builtin_goacc_parlevel_id (GOMP_DIM_VECTOR);
	    ary[ix] = (g << 16) | (w << 8) | v;
	  }
	else
	  ary[ix] = ix;
      }
}

int main ()
{
  int ary[N];
  int ix;
  int exit = 0;
  int ondev = 0;

  for (ix = 0; ix < N;ix++)
    ary[ix] = -1;
  
#pragma acc parallel num_gangs(32) copy(ary) copy(ondev)
  {
    ondev = acc_on_device (acc_device_not_host);
    gang (ary);
  }

  for (ix = 0; ix < N; ix++)
    {
      int expected = ix;
      if(ondev)
	{
	  int g = ix / ((N + 31) / 32);
	  int w = 0;
	  int v = 0;

	  expected = (g << 16) | (w << 8) | v;
	}
      
      if (ary[ix] != expected)
	{
	  exit = 1;
	  printf ("ary[%d]=%x expected %x\n", ix, ary[ix], expected);
	}
    }
  
  return exit;
}
