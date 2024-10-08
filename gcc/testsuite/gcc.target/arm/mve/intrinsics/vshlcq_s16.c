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
**	vshlc	q[0-9]+, (?:ip|fp|r[0-9]+), #[0-9]+(?:	@.*|)
**	...
*/
int16x8_t
foo (int16x8_t a, uint32_t *b)
{
  return vshlcq_s16 (a, b, 1);
}


/*
**foo1:
**	...
**	vshlc	q[0-9]+, (?:ip|fp|r[0-9]+), #[0-9]+(?:	@.*|)
**	...
*/
int16x8_t
foo1 (int16x8_t a, uint32_t *b)
{
  return vshlcq (a, b, 1);
}

#ifdef __cplusplus
}
#endif

/* { dg-final { scan-assembler-not "__ARM_undef" } } */
