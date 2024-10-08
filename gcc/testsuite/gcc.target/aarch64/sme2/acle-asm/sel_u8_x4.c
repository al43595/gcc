/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sme2_acle.h"

/*
** sel_z0_pn0_z0_z4:
**	mov	p([0-9]+)\.b, p0\.b
**	sel	{z0\.b - z3\.b}, pn\1, {z0\.b - z3\.b}, {z4\.b - z7\.b}
**	ret
*/
TEST_XN (sel_z0_pn0_z0_z4, svuint8x4_t, z0,
	 svsel_u8_x4 (pn0, z0, z4),
	 svsel (pn0, z0, z4))

/*
** sel_z0_pn7_z0_z4:
**	mov	p([0-9]+)\.b, p7\.b
**	sel	{z0\.b - z3\.b}, pn\1, {z0\.b - z3\.b}, {z4\.b - z7\.b}
**	ret
*/
TEST_XN (sel_z0_pn7_z0_z4, svuint8x4_t, z0,
	 svsel_u8_x4 (pn7, z0, z4),
	 svsel (pn7, z0, z4))

/*
** sel_z0_pn8_z4_z28:
**	sel	{z0\.b - z3\.b}, pn8, {z4\.b - z7\.b}, {z28\.b - z31\.b}
**	ret
*/
TEST_XN (sel_z0_pn8_z4_z28, svuint8x4_t, z0,
	 svsel_u8_x4 (pn8, z4, z28),
	 svsel (pn8, z4, z28))

/*
** sel_z4_pn8_z18_z0:
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	sel	{z4\.b - z7\.b}, pn8, {[^}]+}, {z0\.b - z3\.b}
**	ret
*/
TEST_XN (sel_z4_pn8_z18_z0, svuint8x4_t, z4,
	 svsel_u8_x4 (pn8, z18, z0),
	 svsel (pn8, z18, z0))

/*
** sel_z18_pn15_z28_z4:
**	sel	{[^}]+}, pn15, {z28\.b - z31\.b}, {z4\.b - z7\.b}
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	ret
*/
TEST_XN (sel_z18_pn15_z28_z4, svuint8x4_t, z18,
	 svsel_u8_x4 (pn15, z28, z4),
	 svsel (pn15, z28, z4))

/*
** sel_z18_pn8_z18_z4:
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	sel	{[^}]+}, pn8, {[^}]+}, {z4\.b - z7\.b}
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	ret
*/
TEST_XN (sel_z18_pn8_z18_z4, svuint8x4_t, z18,
	 svsel_u8_x4 (pn8, z18, z4),
	 svsel (pn8, z18, z4))

/*
** sel_z23_pn15_z0_z18:
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	sel	[^\n]+, pn15, {z0\.b - z3\.b}, {[^}]+}
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	mov	[^\n]+
**	ret
*/
TEST_XN (sel_z23_pn15_z0_z18, svuint8x4_t, z23,
	 svsel_u8_x4 (pn15, z0, z18),
	 svsel (pn15, z0, z18))
