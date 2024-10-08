/* { dg-skip-if "" { *-*-* } { "-DSTREAMING_COMPATIBLE" } { "" } } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" { target { ! ilp32 } } } } */

#include "test_sve_acle.h"

/*
** ld1uw_gather_u64_tied1:
**	ld1w	z0\.d, p0/z, \[z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_u64_tied1, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_u64 (p0, z0),
		     z0_res = svld1uw_gather_u64 (p0, z0))

/*
** ld1uw_gather_u64_untied:
**	ld1w	z0\.d, p0/z, \[z1\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_u64_untied, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_u64 (p0, z1),
		     z0_res = svld1uw_gather_u64 (p0, z1))

/*
** ld1uw_gather_x0_u64_offset:
**	ld1w	z0\.d, p0/z, \[x0, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_x0_u64_offset, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_offset_u64 (p0, z0, x0),
		     z0_res = svld1uw_gather_offset_u64 (p0, z0, x0))

/*
** ld1uw_gather_m4_u64_offset:
**	mov	(x[0-9]+), #?-4
**	ld1w	z0\.d, p0/z, \[\1, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_m4_u64_offset, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_offset_u64 (p0, z0, -4),
		     z0_res = svld1uw_gather_offset_u64 (p0, z0, -4))

/*
** ld1uw_gather_0_u64_offset:
**	ld1w	z0\.d, p0/z, \[z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_0_u64_offset, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_offset_u64 (p0, z0, 0),
		     z0_res = svld1uw_gather_offset_u64 (p0, z0, 0))

/*
** ld1uw_gather_5_u64_offset:
**	mov	(x[0-9]+), #?5
**	ld1w	z0\.d, p0/z, \[\1, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_5_u64_offset, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_offset_u64 (p0, z0, 5),
		     z0_res = svld1uw_gather_offset_u64 (p0, z0, 5))

/*
** ld1uw_gather_6_u64_offset:
**	mov	(x[0-9]+), #?6
**	ld1w	z0\.d, p0/z, \[\1, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_6_u64_offset, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_offset_u64 (p0, z0, 6),
		     z0_res = svld1uw_gather_offset_u64 (p0, z0, 6))

/*
** ld1uw_gather_7_u64_offset:
**	mov	(x[0-9]+), #?7
**	ld1w	z0\.d, p0/z, \[\1, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_7_u64_offset, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_offset_u64 (p0, z0, 7),
		     z0_res = svld1uw_gather_offset_u64 (p0, z0, 7))

/*
** ld1uw_gather_8_u64_offset:
**	ld1w	z0\.d, p0/z, \[z0\.d, #8\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_8_u64_offset, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_offset_u64 (p0, z0, 8),
		     z0_res = svld1uw_gather_offset_u64 (p0, z0, 8))

/*
** ld1uw_gather_124_u64_offset:
**	ld1w	z0\.d, p0/z, \[z0\.d, #124\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_124_u64_offset, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_offset_u64 (p0, z0, 124),
		     z0_res = svld1uw_gather_offset_u64 (p0, z0, 124))

/*
** ld1uw_gather_128_u64_offset:
**	mov	(x[0-9]+), #?128
**	ld1w	z0\.d, p0/z, \[\1, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_128_u64_offset, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_offset_u64 (p0, z0, 128),
		     z0_res = svld1uw_gather_offset_u64 (p0, z0, 128))

/*
** ld1uw_gather_x0_u64_index:
**	lsl	(x[0-9]+), x0, #?2
**	ld1w	z0\.d, p0/z, \[\1, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_x0_u64_index, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_index_u64 (p0, z0, x0),
		     z0_res = svld1uw_gather_index_u64 (p0, z0, x0))

/*
** ld1uw_gather_m1_u64_index:
**	mov	(x[0-9]+), #?-4
**	ld1w	z0\.d, p0/z, \[\1, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_m1_u64_index, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_index_u64 (p0, z0, -1),
		     z0_res = svld1uw_gather_index_u64 (p0, z0, -1))

/*
** ld1uw_gather_0_u64_index:
**	ld1w	z0\.d, p0/z, \[z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_0_u64_index, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_index_u64 (p0, z0, 0),
		     z0_res = svld1uw_gather_index_u64 (p0, z0, 0))

/*
** ld1uw_gather_5_u64_index:
**	ld1w	z0\.d, p0/z, \[z0\.d, #20\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_5_u64_index, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_index_u64 (p0, z0, 5),
		     z0_res = svld1uw_gather_index_u64 (p0, z0, 5))

/*
** ld1uw_gather_31_u64_index:
**	ld1w	z0\.d, p0/z, \[z0\.d, #124\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_31_u64_index, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_index_u64 (p0, z0, 31),
		     z0_res = svld1uw_gather_index_u64 (p0, z0, 31))

/*
** ld1uw_gather_32_u64_index:
**	mov	(x[0-9]+), #?128
**	ld1w	z0\.d, p0/z, \[\1, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_ZS (ld1uw_gather_32_u64_index, svuint64_t, svuint64_t,
		     z0_res = svld1uw_gather_u64base_index_u64 (p0, z0, 32),
		     z0_res = svld1uw_gather_index_u64 (p0, z0, 32))

/*
** ld1uw_gather_x0_u64_s64offset:
**	ld1w	z0\.d, p0/z, \[x0, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_x0_u64_s64offset, svuint64_t, uint32_t, svint64_t,
		     z0_res = svld1uw_gather_s64offset_u64 (p0, x0, z0),
		     z0_res = svld1uw_gather_offset_u64 (p0, x0, z0))

/*
** ld1uw_gather_tied1_u64_s64offset:
**	ld1w	z0\.d, p0/z, \[x0, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_tied1_u64_s64offset, svuint64_t, uint32_t, svint64_t,
		     z0_res = svld1uw_gather_s64offset_u64 (p0, x0, z0),
		     z0_res = svld1uw_gather_offset_u64 (p0, x0, z0))

/*
** ld1uw_gather_untied_u64_s64offset:
**	ld1w	z0\.d, p0/z, \[x0, z1\.d\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_untied_u64_s64offset, svuint64_t, uint32_t, svint64_t,
		     z0_res = svld1uw_gather_s64offset_u64 (p0, x0, z1),
		     z0_res = svld1uw_gather_offset_u64 (p0, x0, z1))

/*
** ld1uw_gather_ext_u64_s64offset:
**	ld1w	z0\.d, p0/z, \[x0, z1\.d, sxtw\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_ext_u64_s64offset, svuint64_t, uint32_t, svint64_t,
		     z0_res = svld1uw_gather_s64offset_u64 (p0, x0, svextw_s64_x (p0, z1)),
		     z0_res = svld1uw_gather_offset_u64 (p0, x0, svextw_x (p0, z1)))

/*
** ld1uw_gather_x0_u64_u64offset:
**	ld1w	z0\.d, p0/z, \[x0, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_x0_u64_u64offset, svuint64_t, uint32_t, svuint64_t,
		     z0_res = svld1uw_gather_u64offset_u64 (p0, x0, z0),
		     z0_res = svld1uw_gather_offset_u64 (p0, x0, z0))

/*
** ld1uw_gather_tied1_u64_u64offset:
**	ld1w	z0\.d, p0/z, \[x0, z0\.d\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_tied1_u64_u64offset, svuint64_t, uint32_t, svuint64_t,
		     z0_res = svld1uw_gather_u64offset_u64 (p0, x0, z0),
		     z0_res = svld1uw_gather_offset_u64 (p0, x0, z0))

/*
** ld1uw_gather_untied_u64_u64offset:
**	ld1w	z0\.d, p0/z, \[x0, z1\.d\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_untied_u64_u64offset, svuint64_t, uint32_t, svuint64_t,
		     z0_res = svld1uw_gather_u64offset_u64 (p0, x0, z1),
		     z0_res = svld1uw_gather_offset_u64 (p0, x0, z1))

/*
** ld1uw_gather_ext_u64_u64offset:
**	ld1w	z0\.d, p0/z, \[x0, z1\.d, uxtw\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_ext_u64_u64offset, svuint64_t, uint32_t, svuint64_t,
		     z0_res = svld1uw_gather_u64offset_u64 (p0, x0, svextw_u64_x (p0, z1)),
		     z0_res = svld1uw_gather_offset_u64 (p0, x0, svextw_x (p0, z1)))

/*
** ld1uw_gather_x0_u64_s64index:
**	ld1w	z0\.d, p0/z, \[x0, z0\.d, lsl 2\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_x0_u64_s64index, svuint64_t, uint32_t, svint64_t,
		     z0_res = svld1uw_gather_s64index_u64 (p0, x0, z0),
		     z0_res = svld1uw_gather_index_u64 (p0, x0, z0))

/*
** ld1uw_gather_tied1_u64_s64index:
**	ld1w	z0\.d, p0/z, \[x0, z0\.d, lsl 2\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_tied1_u64_s64index, svuint64_t, uint32_t, svint64_t,
		     z0_res = svld1uw_gather_s64index_u64 (p0, x0, z0),
		     z0_res = svld1uw_gather_index_u64 (p0, x0, z0))

/*
** ld1uw_gather_untied_u64_s64index:
**	ld1w	z0\.d, p0/z, \[x0, z1\.d, lsl 2\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_untied_u64_s64index, svuint64_t, uint32_t, svint64_t,
		     z0_res = svld1uw_gather_s64index_u64 (p0, x0, z1),
		     z0_res = svld1uw_gather_index_u64 (p0, x0, z1))

/*
** ld1uw_gather_ext_u64_s64index:
**	ld1w	z0\.d, p0/z, \[x0, z1\.d, sxtw 2\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_ext_u64_s64index, svuint64_t, uint32_t, svint64_t,
		     z0_res = svld1uw_gather_s64index_u64 (p0, x0, svextw_s64_x (p0, z1)),
		     z0_res = svld1uw_gather_index_u64 (p0, x0, svextw_x (p0, z1)))

/*
** ld1uw_gather_x0_u64_u64index:
**	ld1w	z0\.d, p0/z, \[x0, z0\.d, lsl 2\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_x0_u64_u64index, svuint64_t, uint32_t, svuint64_t,
		     z0_res = svld1uw_gather_u64index_u64 (p0, x0, z0),
		     z0_res = svld1uw_gather_index_u64 (p0, x0, z0))

/*
** ld1uw_gather_tied1_u64_u64index:
**	ld1w	z0\.d, p0/z, \[x0, z0\.d, lsl 2\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_tied1_u64_u64index, svuint64_t, uint32_t, svuint64_t,
		     z0_res = svld1uw_gather_u64index_u64 (p0, x0, z0),
		     z0_res = svld1uw_gather_index_u64 (p0, x0, z0))

/*
** ld1uw_gather_untied_u64_u64index:
**	ld1w	z0\.d, p0/z, \[x0, z1\.d, lsl 2\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_untied_u64_u64index, svuint64_t, uint32_t, svuint64_t,
		     z0_res = svld1uw_gather_u64index_u64 (p0, x0, z1),
		     z0_res = svld1uw_gather_index_u64 (p0, x0, z1))

/*
** ld1uw_gather_ext_u64_u64index:
**	ld1w	z0\.d, p0/z, \[x0, z1\.d, uxtw 2\]
**	ret
*/
TEST_LOAD_GATHER_SZ (ld1uw_gather_ext_u64_u64index, svuint64_t, uint32_t, svuint64_t,
		     z0_res = svld1uw_gather_u64index_u64 (p0, x0, svextw_u64_x (p0, z1)),
		     z0_res = svld1uw_gather_index_u64 (p0, x0, svextw_x (p0, z1)))
