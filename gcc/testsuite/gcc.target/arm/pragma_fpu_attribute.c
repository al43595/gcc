/* Test for target attribute assembly extension generations.  */
/* { dg-do compile } */
/* { dg-require-effective-target arm_fp_ok } */
/* { dg-add-options arm_fp } */

#include <stdint.h>

extern uint32_t bar ();

#pragma GCC target("fpu=vfpv3-d16")

extern float fmaf (float, float, float);

float
__attribute__((target("fpu=vfpv4"))) vfma32 (float x, float y, float z)
{
  return fmaf (x, y, z);
}

uint32_t restored ()
{
  return bar();
}

/* We can't tell exactly how many times the following tests will match because
   command-line options may cause additional instances to be generated, but
   each must be present at least once.  */
/* { dg-final { scan-assembler {\.fpu\s+vfpv4\n} } } */
/* { dg-final { scan-assembler {\.fpu\s+vfpv3-d16\n} } } */
