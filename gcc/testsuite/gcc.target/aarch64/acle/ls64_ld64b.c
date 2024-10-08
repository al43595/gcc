/* { dg-do compile } */
/* { dg-options "-march=armv8-a+ls64 -O2" } */

#ifndef __ARM_FEATURE_LS64
#error "__ARM_FEATURE_LS64 is not defined but should be!"
#endif

#include <arm_acle.h>

data512_t
func(const void * addr) {
  return __arm_ld64b (addr);
}

/* { dg-final { scan-assembler-times {ld64b\t} 1 } } */
