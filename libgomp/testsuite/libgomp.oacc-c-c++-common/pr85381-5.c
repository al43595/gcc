/* { dg-do run { target openacc_nvidia_accel_selected } }
   { dg-skip-if "" { *-*-* } { "*" } { "-O2" } } */
/* { dg-additional-options "-foffload=-fdump-rtl-mach" } */

#define n 1024

int
main (void)
{
  #pragma acc parallel vector_length(128)
  {
    #pragma acc loop vector
    for (int i = 0; i < n; i++)
      ;

    #pragma acc loop vector
    for (int i = 0; i < n; i++)
      ;
  }

  return 0;
}

/* { dg-final { scan-offload-rtl-dump-not "nvptx_barsync" "mach" } } */
