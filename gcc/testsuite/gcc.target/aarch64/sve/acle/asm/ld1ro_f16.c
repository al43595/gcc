/* { dg-skip-if "" { *-*-* } { "-DSTREAMING_COMPATIBLE" } { "" } } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" { target { ! ilp32 } } } } */
/* { dg-additional-options "-march=armv8.6-a+f64mm" } */
/* { dg-require-effective-target aarch64_asm_f64mm_ok }  */

#include "test_sve_acle.h"

/*
** ld1ro_f16_base:
**	ld1roh	z0\.h, p0/z, \[x0\]
**	ret
*/
TEST_LOAD (ld1ro_f16_base, svfloat16_t, float16_t,
	   z0 = svld1ro_f16 (p0, x0),
	   z0 = svld1ro (p0, x0))

/*
** ld1ro_f16_index:
**	ld1roh	z0\.h, p0/z, \[x0, x1, lsl 1\]
**	ret
*/
TEST_LOAD (ld1ro_f16_index, svfloat16_t, float16_t,
	   z0 = svld1ro_f16 (p0, x0 + x1),
	   z0 = svld1ro (p0, x0 + x1))

/*
** ld1ro_f16_1:
**	add	(x[0-9]+), x0, #?2
**	ld1roh	z0\.h, p0/z, \[\1\]
**	ret
*/
TEST_LOAD (ld1ro_f16_1, svfloat16_t, float16_t,
	   z0 = svld1ro_f16 (p0, x0 + 1),
	   z0 = svld1ro (p0, x0 + 1))

/*
** ld1ro_f16_8:
**	add	(x[0-9]+), x0, #?16
**	ld1roh	z0\.h, p0/z, \[\1\]
**	ret
*/
TEST_LOAD (ld1ro_f16_8, svfloat16_t, float16_t,
	   z0 = svld1ro_f16 (p0, x0 + 8),
	   z0 = svld1ro (p0, x0 + 8))

/*
** ld1ro_f16_128:
**	add	(x[0-9]+), x0, #?256
**	ld1roh	z0\.h, p0/z, \[\1\]
**	ret
*/
TEST_LOAD (ld1ro_f16_128, svfloat16_t, float16_t,
	   z0 = svld1ro_f16 (p0, x0 + 128),
	   z0 = svld1ro (p0, x0 + 128))

/*
** ld1ro_f16_m1:
**	sub	(x[0-9]+), x0, #?2
**	ld1roh	z0\.h, p0/z, \[\1\]
**	ret
*/
TEST_LOAD (ld1ro_f16_m1, svfloat16_t, float16_t,
	   z0 = svld1ro_f16 (p0, x0 - 1),
	   z0 = svld1ro (p0, x0 - 1))

/*
** ld1ro_f16_m8:
**	sub	(x[0-9]+), x0, #?16
**	ld1roh	z0\.h, p0/z, \[\1\]
**	ret
*/
TEST_LOAD (ld1ro_f16_m8, svfloat16_t, float16_t,
	   z0 = svld1ro_f16 (p0, x0 - 8),
	   z0 = svld1ro (p0, x0 - 8))

/*
** ld1ro_f16_m144:
**	sub	(x[0-9]+), x0, #?288
**	ld1roh	z0\.h, p0/z, \[\1\]
**	ret
*/
TEST_LOAD (ld1ro_f16_m144, svfloat16_t, float16_t,
	   z0 = svld1ro_f16 (p0, x0 - 144),
	   z0 = svld1ro (p0, x0 - 144))

/*
** ld1ro_f16_16:
**	ld1roh	z0\.h, p0/z, \[x0, #?32\]
**	ret
*/
TEST_LOAD (ld1ro_f16_16, svfloat16_t, float16_t,
	   z0 = svld1ro_f16 (p0, x0 + 16),
	   z0 = svld1ro (p0, x0 + 16))

/*
** ld1ro_f16_112:
**	ld1roh	z0\.h, p0/z, \[x0, #?224\]
**	ret
*/
TEST_LOAD (ld1ro_f16_112, svfloat16_t, float16_t,
	   z0 = svld1ro_f16 (p0, x0 + 112),
	   z0 = svld1ro (p0, x0 + 112))

/*
** ld1ro_f16_m16:
**	ld1roh	z0\.h, p0/z, \[x0, #?-32\]
**	ret
*/
TEST_LOAD (ld1ro_f16_m16, svfloat16_t, float16_t,
	   z0 = svld1ro_f16 (p0, x0 - 16),
	   z0 = svld1ro (p0, x0 - 16))

/*
** ld1ro_f16_m128:
**	ld1roh	z0\.h, p0/z, \[x0, #?-256\]
**	ret
*/
TEST_LOAD (ld1ro_f16_m128, svfloat16_t, float16_t,
	   z0 = svld1ro_f16 (p0, x0 - 128),
	   z0 = svld1ro (p0, x0 - 128))

