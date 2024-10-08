/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sme_acle.h"

#pragma GCC target "+sme-i16i64"

/*
** mops_za64_s16_0_p0_p1_z0_z1:
**	smops	za0\.d, p0/m, p1/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_ZA (mops_za64_s16_0_p0_p1_z0_z1, svint16_t,
		 svmops_za64_s16_m (0, p0, p1, z0, z1),
		 svmops_za64_m (0, p0, p1, z0, z1))

/*
** mops_za64_s16_0_p1_p0_z1_z0:
**	smops	za0\.d, p1/m, p0/m, z1\.h, z0\.h
**	ret
*/
TEST_UNIFORM_ZA (mops_za64_s16_0_p1_p0_z1_z0, svint16_t,
		 svmops_za64_s16_m (0, p1, p0, z1, z0),
		 svmops_za64_m (0, p1, p0, z1, z0))

/*
** mops_za64_s16_7_p0_p1_z0_z1:
**	smops	za7\.d, p0/m, p1/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_ZA (mops_za64_s16_7_p0_p1_z0_z1, svint16_t,
		 svmops_za64_s16_m (7, p0, p1, z0, z1),
		 svmops_za64_m (7, p0, p1, z0, z1))

/*
** mops_za64_u16_0_p0_p1_z0_z1:
**	umops	za0\.d, p0/m, p1/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_ZA (mops_za64_u16_0_p0_p1_z0_z1, svuint16_t,
		 svmops_za64_u16_m (0, p0, p1, z0, z1),
		 svmops_za64_m (0, p0, p1, z0, z1))

/*
** mops_za64_u16_7_p0_p1_z0_z1:
**	umops	za7\.d, p0/m, p1/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_ZA (mops_za64_u16_7_p0_p1_z0_z1, svuint16_t,
		 svmops_za64_u16_m (7, p0, p1, z0, z1),
		 svmops_za64_m (7, p0, p1, z0, z1))

#pragma GCC target "+nosme-i16i64+sme-f64f64"

/*
** mops_za64_f64_0_p0_p1_z0_z1:
**	fmops	za0\.d, p0/m, p1/m, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_ZA (mops_za64_f64_0_p0_p1_z0_z1, svfloat64_t,
		 svmops_za64_f64_m (0, p0, p1, z0, z1),
		 svmops_za64_m (0, p0, p1, z0, z1))

/*
** mops_za64_f64_7_p0_p1_z0_z1:
**	fmops	za7\.d, p0/m, p1/m, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_ZA (mops_za64_f64_7_p0_p1_z0_z1, svfloat64_t,
		 svmops_za64_f64_m (7, p0, p1, z0, z1),
		 svmops_za64_m (7, p0, p1, z0, z1))
