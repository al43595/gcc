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
**	vmul.i16	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
uint16x8_t
foo (uint16x8_t a, uint16_t b)
{
  return vmulq_n_u16 (a, b);
}


/*
**foo1:
**	...
**	vmul.i16	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
uint16x8_t
foo1 (uint16x8_t a, uint16_t b)
{
  return vmulq (a, b);
}

/*
**foo2:
**	...
**	vmul.i16	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
uint16x8_t
foo2 (uint16x8_t a)
{
  return vmulq (a, 1);
}

#ifdef __cplusplus
}
#endif

/* { dg-final { scan-assembler-not "__ARM_undef" } } */