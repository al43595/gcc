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
**	vmsr	p0, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vpst(?:	@.*|)
**	...
**	vminavt.s8	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
uint8_t
foo (uint8_t a, int8x16_t b, mve_pred16_t p)
{
  return vminavq_p_s8 (a, b, p);
}


/*
**foo1:
**	...
**	vmsr	p0, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vpst(?:	@.*|)
**	...
**	vminavt.s8	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
uint8_t
foo1 (uint8_t a, int8x16_t b, mve_pred16_t p)
{
  return vminavq_p (a, b, p);
}

/*
**foo2:
**	...
**	vmsr	p0, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vpst(?:	@.*|)
**	...
**	vminavt.s8	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
uint8_t
foo2 (int8x16_t b, mve_pred16_t p)
{
  return vminavq_p (1, b, p);
}

#ifdef __cplusplus
}
#endif

/* { dg-final { scan-assembler-not "__ARM_undef" } } */