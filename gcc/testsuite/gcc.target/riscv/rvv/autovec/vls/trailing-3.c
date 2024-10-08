/* { dg-do compile } */
/* { dg-options "-march=rv64gcv_zvfh_zvl4096b -mabi=lp64d -O3 -mrvv-max-lmul=m8" } */

#include "def.h"

DEF_TRAILING (v8si, int32_t, 8, var0, var1, var2, var3, var3, var3, var3, var3)
DEF_TRAILING (v16si, int32_t, 16, var0, var1, var2, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3)
DEF_TRAILING (v32si, int32_t, 32, var0, var1, var2, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3)
DEF_TRAILING (v64si, int32_t, 64, var0, var1, var2, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3)
DEF_TRAILING (v128si, int32_t, 128, var0, var1, var2, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
	    var3, var3, var3, var3, var3, var3, var3, var3, var3, var3)
DEF_TRAILING (
  v256si, int32_t, 256, var0, var1, var2, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3)
DEF_TRAILING (
  v512si, int32_t, 512, var0, var1, var2, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3)
DEF_TRAILING (
  v1024si, int32_t, 1024, var0, var1, var2, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3, var3,
  var3)

/* { dg-final { scan-assembler-times {vslide1up\.vx} 24 } } */
