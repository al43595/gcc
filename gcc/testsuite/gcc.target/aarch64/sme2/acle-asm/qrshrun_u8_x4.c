/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sme2_acle.h"

/*
** qrshrun_z0_z0_1:
**	sqrshrun	z0\.b, {z0\.s - z3\.s}, #1
**	ret
*/
TEST_X4_NARROW (qrshrun_z0_z0_1, svint32x4_t, svuint8_t,
		z0_res = svqrshrun_n_u8_s32_x4 (z0, 1),
		z0_res = svqrshrun_u8 (z0, 1))

/*
** qrshrun_z0_z4_32:
**	sqrshrun	z0\.b, {z4\.s - z7\.s}, #32
**	ret
*/
TEST_X4_NARROW (qrshrun_z0_z4_32, svint32x4_t, svuint8_t,
		z0_res = svqrshrun_n_u8_s32_x4 (z4, 32),
		z0_res = svqrshrun_u8 (z4, 32))

/*
** qrshrun_z0_z21_2:
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	sqrshrun	z0\.b, [^\n]+, #2
**	ret
*/
TEST_X4_NARROW (qrshrun_z0_z21_2, svint32x4_t, svuint8_t,
		z0_res = svqrshrun_n_u8_s32_x4 (z21, 2),
		z0_res = svqrshrun_u8 (z21, 2))

/*
** qrshrun_z25_z26_12:
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	sqrshrun	z25\.b, [^\n]+, #12
**	ret
*/
TEST_X4_NARROW (qrshrun_z25_z26_12, svint32x4_t, svuint8_t,
		z25 = svqrshrun_n_u8_s32_x4 (z26, 12),
		z25 = svqrshrun_u8 (z26, 12))

/*
** qrshrun_z25_z0_16:
**	sqrshrun	z25\.b, {z0\.s - z3\.s}, #16
**	ret
*/
TEST_X4_NARROW (qrshrun_z25_z0_16, svint32x4_t, svuint8_t,
		z25 = svqrshrun_n_u8_s32_x4 (z0, 16),
		z25 = svqrshrun_u8 (z0, 16))

/*
** qrshrun_z22_z16_31:
**	sqrshrun	z22\.b, {z16\.s - z19\.s}, #31
**	ret
*/
TEST_X4_NARROW (qrshrun_z22_z16_31, svint32x4_t, svuint8_t,
		z22_res = svqrshrun_n_u8_s32_x4 (z16, 31),
		z22_res = svqrshrun_u8 (z16, 31))
