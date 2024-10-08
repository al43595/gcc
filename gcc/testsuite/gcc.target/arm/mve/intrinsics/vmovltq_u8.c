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
**	vmovlt.u8	q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint16x8_t
foo (uint8x16_t a)
{
  return vmovltq_u8 (a);
}


/*
**foo1:
**	...
**	vmovlt.u8	q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint16x8_t
foo1 (uint8x16_t a)
{
  return vmovltq (a);
}

#ifdef __cplusplus
}
#endif

/* { dg-final { scan-assembler-not "__ARM_undef" } } */
