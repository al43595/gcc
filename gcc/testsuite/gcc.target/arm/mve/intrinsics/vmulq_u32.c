/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
**foo:
**	...
**	vmul.i32	q[0-9]+, q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint32x4_t
foo (uint32x4_t a, uint32x4_t b)
{
  return vmulq_u32 (a, b);
}


/*
**foo1:
**	...
**	vmul.i32	q[0-9]+, q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint32x4_t
foo1 (uint32x4_t a, uint32x4_t b)
{
  return vmulq (a, b);
}

#ifdef __cplusplus
}
#endif

/* { dg-final { scan-assembler-not "__ARM_undef" } } */