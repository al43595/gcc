/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#pragma GCC target "+sme-i16i64"

#include "test_sme2_acle.h"

/*
** mls_lane_0_z0_z4_0:
**	mov	(w8|w9|w10|w11), #?0
**	smlsll	za\.d\[\1, 0:3, vgx2\], {z0\.h - z1\.h}, z4\.h\[0\]
**	ret
*/
TEST_ZA_LANE (mls_lane_0_z0_z4_0, svint16x2_t, svint16_t,
	      svmls_lane_za64_s16_vg4x2 (0, z0, z4, 0),
	      svmls_lane_za64_vg4x2 (0, z0, z4, 0))

/*
** mls_lane_w0_z0_z7_1:
**	mov	(w8|w9|w10|w11), w0
**	smlsll	za\.d\[\1, 0:3, vgx2\], {z0\.h - z1\.h}, z7\.h\[1\]
**	ret
*/
TEST_ZA_LANE (mls_lane_w0_z0_z7_1, svint16x2_t, svint16_t,
	      svmls_lane_za64_s16_vg4x2 (w0, z0, z7, 1),
	      svmls_lane_za64_vg4x2 (w0, z0, z7, 1))

/*
** mls_lane_w8_z28_z4_2:
**	smlsll	za\.d\[w8, 0:3, vgx2\], {z28\.h - z29\.h}, z4\.h\[2\]
**	ret
*/
TEST_ZA_LANE (mls_lane_w8_z28_z4_2, svint16x2_t, svint16_t,
	      svmls_lane_za64_s16_vg4x2 (w8, z28, z4, 2),
	      svmls_lane_za64_vg4x2 (w8, z28, z4, 2))

/*
** mls_lane_w11p4_z0_z4_3:
**	smlsll	za\.d\[w11, 4:7, vgx2\], {z0\.h - z1\.h}, z4\.h\[3\]
**	ret
*/
TEST_ZA_LANE (mls_lane_w11p4_z0_z4_3, svint16x2_t, svint16_t,
	      svmls_lane_za64_s16_vg4x2 (w11 + 4, z0, z4, 3),
	      svmls_lane_za64_vg4x2 (w11 + 4, z0, z4, 3))

/*
** mls_lane_w8p6_z0_z4_4:
**	add	(w8|w9|w10|w11), w8, #?6
**	smlsll	za\.d\[\1, 0:3, vgx2\], {z0\.h - z1\.h}, z4\.h\[4\]
**	ret
*/
TEST_ZA_LANE (mls_lane_w8p6_z0_z4_4, svint16x2_t, svint16_t,
	      svmls_lane_za64_s16_vg4x2 (w8 + 6, z0, z4, 4),
	      svmls_lane_za64_vg4x2 (w8 + 6, z0, z4, 4))

/*
** mls_lane_w8p7_z0_z4_5:
**	add	(w8|w9|w10|w11), w8, #?7
**	smlsll	za\.d\[\1, 0:3, vgx2\], {z0\.h - z1\.h}, z4\.h\[5\]
**	ret
*/
TEST_ZA_LANE (mls_lane_w8p7_z0_z4_5, svint16x2_t, svint16_t,
	      svmls_lane_za64_s16_vg4x2 (w8 + 7, z0, z4, 5),
	      svmls_lane_za64_vg4x2 (w8 + 7, z0, z4, 5))

/*
** mls_lane_w8p8_z0_z4_6:
**	add	(w8|w9|w10|w11), w8, #?8
**	smlsll	za\.d\[\1, 0:3, vgx2\], {z0\.h - z1\.h}, z4\.h\[6\]
**	ret
*/
TEST_ZA_LANE (mls_lane_w8p8_z0_z4_6, svint16x2_t, svint16_t,
	      svmls_lane_za64_s16_vg4x2 (w8 + 8, z0, z4, 6),
	      svmls_lane_za64_vg4x2 (w8 + 8, z0, z4, 6))

/*
** mls_lane_w0m1_z0_z4_7:
**	sub	(w8|w9|w10|w11), w0, #?1
**	smlsll	za\.d\[\1, 0:3, vgx2\], {z0\.h - z1\.h}, z4\.h\[7\]
**	ret
*/
TEST_ZA_LANE (mls_lane_w0m1_z0_z4_7, svint16x2_t, svint16_t,
	      svmls_lane_za64_s16_vg4x2 (w0 - 1, z0, z4, 7),
	      svmls_lane_za64_vg4x2 (w0 - 1, z0, z4, 7))

/*
** mls_lane_w8_z4_z15_0:
**	str	d15, \[sp, #?-16\]!
**	smlsll	za\.d\[w8, 0:3, vgx2\], {z4\.h - z5\.h}, z15\.h\[0\]
**	ldr	d15, \[sp\], #?16
**	ret
*/
TEST_ZA_LANE_Z15 (mls_lane_w8_z4_z15_0, svint16x2_t, svint16_t,
		  svmls_lane_za64_s16_vg4x2 (w8, z4, z15, 0),
		  svmls_lane_za64_vg4x2 (w8, z4, z15, 0))

/*
** mls_lane_w8_z28_z16_1:
**	mov	(z[0-7]).d, z16.d
**	smlsll	za\.d\[w8, 0:3, vgx2\], {z28\.h - z29\.h}, \1\.h\[1\]
**	ret
*/
TEST_ZA_LANE (mls_lane_w8_z28_z16_1, svint16x2_t, svint16_t,
	      svmls_lane_za64_s16_vg4x2 (w8, z28, z16, 1),
	      svmls_lane_za64_vg4x2 (w8, z28, z16, 1))

/*
** mls_lane_w8_z17_z7_3:
**	mov	[^\n]+
**	mov	[^\n]+
**	smlsll	za\.d\[w8, 0:3, vgx2\], [^\n]+, z7\.h\[3\]
**	ret
*/
TEST_ZA_LANE (mls_lane_w8_z17_z7_3, svint16x2_t, svint16_t,
	      svmls_lane_za64_s16_vg4x2 (w8, z17, z7, 3),
	      svmls_lane_za64_vg4x2 (w8, z17, z7, 3))

/*
** mls_lane_w8_z22_z4_5:
**	smlsll	za\.d\[w8, 0:3, vgx2\], {z22\.h - z23\.h}, z4\.h\[5\]
**	ret
*/
TEST_ZA_LANE (mls_lane_w8_z22_z4_5, svint16x2_t, svint16_t,
	      svmls_lane_za64_s16_vg4x2 (w8, z22, z4, 5),
	      svmls_lane_za64_vg4x2 (w8, z22, z4, 5))
