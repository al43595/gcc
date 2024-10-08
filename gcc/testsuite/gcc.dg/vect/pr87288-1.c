#include "tree-vect.h"

#define N (VECTOR_BITS / 32)
#define MAX_COUNT 4

void __attribute__ ((noipa))
run (int *restrict a, int *restrict b, int count)
{
  for (int i = 0; i < count * N; ++i)
    {
      a[i * 2] = b[i * 2] + count;
      a[i * 2 + 1] = count;
    }
}

void __attribute__ ((noipa))
check (int *restrict a, int count)
{
#pragma GCC novector
  for (int i = 0; i < count * N; ++i)
    if (a[i * 2] != i * 41 + count || a[i * 2 + 1] != count)
      __builtin_abort ();
  if (a[count * 2 * N] != 999)
    __builtin_abort ();
}

int a[N * MAX_COUNT * 2 + 1], b[N * MAX_COUNT * 2];

int
main (void)
{
  check_vect ();

  for (int i = 0; i < N * MAX_COUNT; ++i)
    {
      b[i * 2] = i * 41;
      asm volatile ("" ::: "memory");
    }

  for (int i = 0; i <= MAX_COUNT; ++i)
    {
      a[i * 2 * N] = 999;
      run (a, b, i);
      check (a, i);
    }

  return 0;
}

/* { dg-final { scan-tree-dump-times {LOOP VECTORIZED} 1 "vect" { target { { vect_int && vect_perm } && vect_element_align } } } } */
