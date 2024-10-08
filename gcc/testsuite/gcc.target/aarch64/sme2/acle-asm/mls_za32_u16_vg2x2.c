/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sme2_acle.h"

/*
** mls_0_z0_z0:
**	mov	(w8|w9|w10|w11), #?0
**	umlsl	za\.s\[\1, 0:1, vgx2\], {z0\.h - z1\.h}, {z0\.h - z1\.h}
**	ret
*/
TEST_ZA_XN (mls_0_z0_z0, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (0, z0, z0),
	    svmls_za32_vg2x2 (0, z0, z0))

/*
** mls_w0_z0_z0:
**	mov	(w8|w9|w10|w11), w0
**	umlsl	za\.s\[\1, 0:1, vgx2\], {z0\.h - z1\.h}, {z0\.h - z1\.h}
**	ret
*/
TEST_ZA_XN (mls_w0_z0_z0, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w0, z0, z0),
	    svmls_za32_vg2x2 (w0, z0, z0))

/*
** mls_w8_z0_z4:
**	umlsl	za\.s\[w8, 0:1, vgx2\], {z0\.h - z1\.h}, {z4\.h - z5\.h}
**	ret
*/
TEST_ZA_XN (mls_w8_z0_z4, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w8, z0, z4),
	    svmls_za32_vg2x2 (w8, z0, z4))

/*
** mls_w8_z4_z18:
**	umlsl	za\.s\[w8, 0:1, vgx2\], {z4\.h - z5\.h}, {z18\.h - z19\.h}
**	ret
*/
TEST_ZA_XN (mls_w8_z4_z18, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w8, z4, z18),
	    svmls_za32_vg2x2 (w8, z4, z18))

/* Leave the assembler to check for correctness for misaligned registers.  */

/*
** mls_w8_z0_z23:
**	...
**	umlsl	za\.s\[w8, 0:1, vgx2\], {z0\.h - z1\.h}, [^\n]+
**	ret
*/
TEST_ZA_XN (mls_w8_z0_z23, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w8, z0, z23),
	    svmls_za32_vg2x2 (w8, z0, z23))

/*
** mls_w8_z23_z0:
**	...
**	umlsl	za\.s\[w8, 0:1, vgx2\], [^\n]+, {z0\.h - z1\.h}
**	ret
*/
TEST_ZA_XN (mls_w8_z23_z0, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w8, z23, z0),
	    svmls_za32_vg2x2 (w8, z23, z0))

/*
** mls_w8_z18_z28:
**	umlsl	za\.s\[w8, 0:1, vgx2\], {z18\.h - z19\.h}, {z28\.h - z29\.h}
**	ret
*/
TEST_ZA_XN (mls_w8_z18_z28, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w8, z18, z28),
	    svmls_za32_vg2x2 (w8, z18, z28))

/*
** mls_w8_z28_z4:
**	umlsl	za\.s\[w8, 0:1, vgx2\], {z28\.h - z29\.h}, {z4\.h - z5\.h}
**	ret
*/
TEST_ZA_XN (mls_w8_z28_z4, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w8, z28, z4),
	    svmls_za32_vg2x2 (w8, z28, z4))

/*
** mls_w8p1_z4_z0:
**	add	(w8|w9|w10|w11), w8, #?1
**	umlsl	za\.s\[\1, 0:1, vgx2\], {z4\.h - z5\.h}, {z0\.h - z1\.h}
**	ret
*/
TEST_ZA_XN (mls_w8p1_z4_z0, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w8 + 1, z4, z0),
	    svmls_za32_vg2x2 (w8 + 1, z4, z0))

/*
** mls_w8p2_z4_z0:
**	umlsl	za\.s\[w8, 2:3, vgx2\], {z4\.h - z5\.h}, {z0\.h - z1\.h}
**	ret
*/
TEST_ZA_XN (mls_w8p2_z4_z0, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w8 + 2, z4, z0),
	    svmls_za32_vg2x2 (w8 + 2, z4, z0))

/*
** mls_w8p6_z4_z0:
**	umlsl	za\.s\[w8, 6:7, vgx2\], {z4\.h - z5\.h}, {z0\.h - z1\.h}
**	ret
*/
TEST_ZA_XN (mls_w8p6_z4_z0, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w8 + 6, z4, z0),
	    svmls_za32_vg2x2 (w8 + 6, z4, z0))

/*
** mls_w8p7_z4_z0:
**	add	(w8|w9|w10|w11), w8, #?7
**	umlsl	za\.s\[\1, 0:1, vgx2\], {z4\.h - z5\.h}, {z0\.h - z1\.h}
**	ret
*/
TEST_ZA_XN (mls_w8p7_z4_z0, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w8 + 7, z4, z0),
	    svmls_za32_vg2x2 (w8 + 7, z4, z0))

/*
** mls_w8p8_z4_z4:
**	add	(w8|w9|w10|w11), w8, #?8
**	umlsl	za\.s\[\1, 0:1, vgx2\], {z4\.h - z5\.h}, {z4\.h - z5\.h}
**	ret
*/
TEST_ZA_XN (mls_w8p8_z4_z4, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w8 + 8, z4, z4),
	    svmls_za32_vg2x2 (w8 + 8, z4, z4))

/*
** mls_w8m1_z4_z0:
**	sub	(w8|w9|w10|w11), w8, #?1
**	umlsl	za\.s\[\1, 0:1, vgx2\], {z4\.h - z5\.h}, {z0\.h - z1\.h}
**	ret
*/
TEST_ZA_XN (mls_w8m1_z4_z0, svuint16x2_t,
	    svmls_za32_u16_vg2x2 (w8 - 1, z4, z0),
	    svmls_za32_vg2x2 (w8 - 1, z4, z0))

/*
** mls_single_0_z1_z0:
**	mov	(w8|w9|w10|w11), #?0
**	umlsl	za\.s\[\1, 0:1, vgx2\], {z1\.h - z2\.h}, z0\.h
**	ret
*/
TEST_ZA_SINGLE (mls_single_0_z1_z0, svuint16x2_t, svuint16_t,
	        svmls_single_za32_u16_vg2x2 (0, z1, z0),
	        svmls_za32_vg2x2 (0, z1, z0))

/*
** mls_single_w0_z1_z0:
**	mov	(w8|w9|w10|w11), w0
**	umlsl	za\.s\[\1, 0:1, vgx2\], {z1\.h - z2\.h}, z0\.h
**	ret
*/
TEST_ZA_SINGLE (mls_single_w0_z1_z0, svuint16x2_t, svuint16_t,
	        svmls_single_za32_u16_vg2x2 (w0, z1, z0),
	        svmls_za32_vg2x2 (w0, z1, z0))

/*
** mls_single_w8_z1_z0:
**	umlsl	za\.s\[w8, 0:1, vgx2\], {z1\.h - z2\.h}, z0\.h
**	ret
*/
TEST_ZA_SINGLE (mls_single_w8_z1_z0, svuint16x2_t, svuint16_t,
	        svmls_single_za32_u16_vg2x2 (w8, z1, z0),
	        svmls_za32_vg2x2 (w8, z1, z0))

/*
** mls_single_w8p1_z1_z0:
**	add	(w8|w9|w10|w11), w8, #?1
**	umlsl	za\.s\[\1, 0:1, vgx2\], {z1\.h - z2\.h}, z0\.h
**	ret
*/
TEST_ZA_SINGLE (mls_single_w8p1_z1_z0, svuint16x2_t, svuint16_t,
	        svmls_single_za32_u16_vg2x2 (w8 + 1, z1, z0),
	        svmls_za32_vg2x2 (w8 + 1, z1, z0))

/*
** mls_single_w8p4_z20_z0:
**	umlsl	za\.s\[w8, 4:5, vgx2\], {z20\.h - z21\.h}, z0\.h
**	ret
*/
TEST_ZA_SINGLE (mls_single_w8p4_z20_z0, svuint16x2_t, svuint16_t,
	        svmls_single_za32_u16_vg2x2 (w8 + 4, z20, z0),
	        svmls_za32_vg2x2 (w8 + 4, z20, z0))

/*
** mls_single_w8p6_z27_z0:
**	umlsl	za\.s\[w8, 6:7, vgx2\], {z27\.h - z28\.h}, z0\.h
**	ret
*/
TEST_ZA_SINGLE (mls_single_w8p6_z27_z0, svuint16x2_t, svuint16_t,
	        svmls_single_za32_u16_vg2x2 (w8 + 6, z27, z0),
	        svmls_za32_vg2x2 (w8 + 6, z27, z0))

/*
** mls_single_w8p7_z1_z0:
**	add	(w8|w9|w10|w11), w8, #?7
**	umlsl	za\.s\[\1, 0:1, vgx2\], {z1\.h - z2\.h}, z0\.h
**	ret
*/
TEST_ZA_SINGLE (mls_single_w8p7_z1_z0, svuint16x2_t, svuint16_t,
	        svmls_single_za32_u16_vg2x2 (w8 + 7, z1, z0),
	        svmls_za32_vg2x2 (w8 + 7, z1, z0))

/*
** mls_single_w8p8_z1_z0:
**	add	(w8|w9|w10|w11), w8, #?8
**	umlsl	za\.s\[\1, 0:1, vgx2\], {z1\.h - z2\.h}, z0\.h
**	ret
*/
TEST_ZA_SINGLE (mls_single_w8p8_z1_z0, svuint16x2_t, svuint16_t,
	        svmls_single_za32_u16_vg2x2 (w8 + 8, z1, z0),
	        svmls_za32_vg2x2 (w8 + 8, z1, z0))

/*
** mls_single_w0m1_z1_z0:
**	sub	(w8|w9|w10|w11), w0, #?1
**	umlsl	za\.s\[\1, 0:1, vgx2\], {z1\.h - z2\.h}, z0\.h
**	ret
*/
TEST_ZA_SINGLE (mls_single_w0m1_z1_z0, svuint16x2_t, svuint16_t,
	        svmls_single_za32_u16_vg2x2 (w0 - 1, z1, z0),
	        svmls_za32_vg2x2 (w0 - 1, z1, z0))

/*
** mls_single_w8_z0_z15:
**	str	d15, \[sp, #?-16\]!
**	umlsl	za\.s\[w8, 0:1, vgx2\], {z0\.h - z1\.h}, z15\.h
**	ldr	d15, \[sp\], #?16
**	ret
*/
TEST_ZA_SINGLE_Z15 (mls_single_w8_z0_z15, svuint16x2_t, svuint16_t,
		    svmls_single_za32_u16_vg2x2 (w8, z0, z15),
		    svmls_za32_vg2x2 (w8, z0, z15))

/*
** mls_single_w8_z20_z16:
**	mov	(z[0-7]).d, z16.d
**	umlsl	za\.s\[w8, 0:1, vgx2\], {z20\.h - z21\.h}, \1\.h
**	ret
*/
TEST_ZA_SINGLE (mls_single_w8_z20_z16, svuint16x2_t, svuint16_t,
	        svmls_single_za32_u16_vg2x2 (w8, z20, z16),
	        svmls_za32_vg2x2 (w8, z20, z16))
