/* { dg-do compile { target { powerpc*-*-* } } } */
/* { dg-options "-mdejagnu-cpu=power9 -mvsx" } */
/* { dg-require-effective-target powerpc_vsx } */

#include <altivec.h>
#include <stdbool.h>

bool
test_neg (double *p)
{
  double source = *p;

  return scalar_test_neg (source);
}

/* { dg-final { scan-assembler "xststdcdp" } } */
