#include <stdio.h>
#include "bf16-check.h"
#include "defines.h"
#include "macros.h"
#include "args.h"

struct FloatRegisters fregs;
struct IntegerRegisters iregs;
unsigned int num_fregs, num_iregs;

/* This struct holds values for argument checking.  */
struct
{
  XMM_T i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15,
    i16, i17, i18, i19, i20, i21, i22, i23;
} values;

char *pass;
int failed = 0;

#undef assert
#define assert(c) do { \
  if (!(c)) {failed++; printf ("failed %s\n", pass); } \
} while (0)

#define compare(X1,X2,T) do { \
  assert (memcmp (&X1, &X2, sizeof (T)) == 0); \
} while (0)

void
fun_check_passing_m128bf16_8_values (__m128bf16 i0 ATTRIBUTE_UNUSED,
				     __m128bf16 i1 ATTRIBUTE_UNUSED,
				     __m128bf16 i2 ATTRIBUTE_UNUSED,
				     __m128bf16 i3 ATTRIBUTE_UNUSED,
				     __m128bf16 i4 ATTRIBUTE_UNUSED,
				     __m128bf16 i5 ATTRIBUTE_UNUSED,
				     __m128bf16 i6 ATTRIBUTE_UNUSED,
				     __m128bf16 i7 ATTRIBUTE_UNUSED)
{
  /* Check argument values.  */
  compare (values.i0, i0, __m128bf16);
  compare (values.i1, i1, __m128bf16);
  compare (values.i2, i2, __m128bf16);
  compare (values.i3, i3, __m128bf16);
  compare (values.i4, i4, __m128bf16);
  compare (values.i5, i5, __m128bf16);
  compare (values.i6, i6, __m128bf16);
  compare (values.i7, i7, __m128bf16);
}

void
fun_check_passing_m128bf16_8_regs (__m128bf16 i0 ATTRIBUTE_UNUSED,
				   __m128bf16 i1 ATTRIBUTE_UNUSED,
				   __m128bf16 i2 ATTRIBUTE_UNUSED,
				   __m128bf16 i3 ATTRIBUTE_UNUSED,
				   __m128bf16 i4 ATTRIBUTE_UNUSED,
				   __m128bf16 i5 ATTRIBUTE_UNUSED,
				   __m128bf16 i6 ATTRIBUTE_UNUSED,
				   __m128bf16 i7 ATTRIBUTE_UNUSED)
{
  /* Check register contents.  */
  check_m128_arguments;
}

void
fun_check_passing_m128bf16_20_values (__m128bf16 i0 ATTRIBUTE_UNUSED,
				      __m128bf16 i1 ATTRIBUTE_UNUSED,
				      __m128bf16 i2 ATTRIBUTE_UNUSED,
				      __m128bf16 i3 ATTRIBUTE_UNUSED,
				      __m128bf16 i4 ATTRIBUTE_UNUSED,
				      __m128bf16 i5 ATTRIBUTE_UNUSED,
				      __m128bf16 i6 ATTRIBUTE_UNUSED,
				      __m128bf16 i7 ATTRIBUTE_UNUSED,
				      __m128bf16 i8 ATTRIBUTE_UNUSED,
				      __m128bf16 i9 ATTRIBUTE_UNUSED,
				      __m128bf16 i10 ATTRIBUTE_UNUSED,
				      __m128bf16 i11 ATTRIBUTE_UNUSED,
				      __m128bf16 i12 ATTRIBUTE_UNUSED,
				      __m128bf16 i13 ATTRIBUTE_UNUSED,
				      __m128bf16 i14 ATTRIBUTE_UNUSED,
				      __m128bf16 i15 ATTRIBUTE_UNUSED,
				      __m128bf16 i16 ATTRIBUTE_UNUSED,
				      __m128bf16 i17 ATTRIBUTE_UNUSED,
				      __m128bf16 i18 ATTRIBUTE_UNUSED,
				      __m128bf16 i19 ATTRIBUTE_UNUSED)
{
  /* Check argument values.  */
  compare (values.i0, i0, __m128bf16);
  compare (values.i1, i1, __m128bf16);
  compare (values.i2, i2, __m128bf16);
  compare (values.i3, i3, __m128bf16);
  compare (values.i4, i4, __m128bf16);
  compare (values.i5, i5, __m128bf16);
  compare (values.i6, i6, __m128bf16);
  compare (values.i7, i7, __m128bf16);
  compare (values.i8, i8, __m128bf16);
  compare (values.i9, i9, __m128bf16);
  compare (values.i10, i10, __m128bf16);
  compare (values.i11, i11, __m128bf16);
  compare (values.i12, i12, __m128bf16);
  compare (values.i13, i13, __m128bf16);
  compare (values.i14, i14, __m128bf16);
  compare (values.i15, i15, __m128bf16);
  compare (values.i16, i16, __m128bf16);
  compare (values.i17, i17, __m128bf16);
  compare (values.i18, i18, __m128bf16);
  compare (values.i19, i19, __m128bf16);
}

void
fun_check_passing_m128bf16_20_regs (__m128bf16 i0 ATTRIBUTE_UNUSED,
				    __m128bf16 i1 ATTRIBUTE_UNUSED,
				    __m128bf16 i2 ATTRIBUTE_UNUSED,
				    __m128bf16 i3 ATTRIBUTE_UNUSED,
				    __m128bf16 i4 ATTRIBUTE_UNUSED,
				    __m128bf16 i5 ATTRIBUTE_UNUSED,
				    __m128bf16 i6 ATTRIBUTE_UNUSED,
				    __m128bf16 i7 ATTRIBUTE_UNUSED,
				    __m128bf16 i8 ATTRIBUTE_UNUSED,
				    __m128bf16 i9 ATTRIBUTE_UNUSED,
				    __m128bf16 i10 ATTRIBUTE_UNUSED,
				    __m128bf16 i11 ATTRIBUTE_UNUSED,
				    __m128bf16 i12 ATTRIBUTE_UNUSED,
				    __m128bf16 i13 ATTRIBUTE_UNUSED,
				    __m128bf16 i14 ATTRIBUTE_UNUSED,
				    __m128bf16 i15 ATTRIBUTE_UNUSED,
				    __m128bf16 i16 ATTRIBUTE_UNUSED,
				    __m128bf16 i17 ATTRIBUTE_UNUSED,
				    __m128bf16 i18 ATTRIBUTE_UNUSED,
				    __m128bf16 i19 ATTRIBUTE_UNUSED)
{
  /* Check register contents.  */
  check_m128_arguments;
}

#define def_check_int_passing8(_i0, _i1, _i2, _i3, \
			       _i4, _i5, _i6, _i7, \
			       _func1, _func2, TYPE) \
  values.i0.TYPE[0] = _i0; \
  values.i1.TYPE[0] = _i1; \
  values.i2.TYPE[0] = _i2; \
  values.i3.TYPE[0] = _i3; \
  values.i4.TYPE[0] = _i4; \
  values.i5.TYPE[0] = _i5; \
  values.i6.TYPE[0] = _i6; \
  values.i7.TYPE[0] = _i7; \
  WRAP_CALL(_func1) (_i0, _i1, _i2, _i3, _i4, _i5, _i6, _i7); \
  clear_float_registers; \
  fregs.F0.TYPE[0] = _i0; \
  fregs.F1.TYPE[0] = _i1; \
  fregs.F2.TYPE[0] = _i2; \
  fregs.F3.TYPE[0] = _i3; \
  fregs.F4.TYPE[0] = _i4; \
  fregs.F5.TYPE[0] = _i5; \
  fregs.F6.TYPE[0] = _i6; \
  fregs.F7.TYPE[0] = _i7; \
  num_fregs = 8; \
  WRAP_CALL(_func2) (_i0, _i1, _i2, _i3, _i4, _i5, _i6, _i7);

#define def_check_int_passing20(_i0, _i1, _i2, _i3, _i4, _i5, _i6, \
				_i7, _i8, _i9, _i10, _i11, _i12, _i13, \
				_i14, _i15, _i16, _i17, _i18, _i19, \
				_func1, _func2, TYPE) \
  values.i0.TYPE[0] = _i0; \
  values.i1.TYPE[0] = _i1; \
  values.i2.TYPE[0] = _i2; \
  values.i3.TYPE[0] = _i3; \
  values.i4.TYPE[0] = _i4; \
  values.i5.TYPE[0] = _i5; \
  values.i6.TYPE[0] = _i6; \
  values.i7.TYPE[0] = _i7; \
  values.i8.TYPE[0] = _i8; \
  values.i9.TYPE[0] = _i9; \
  values.i10.TYPE[0] = _i10; \
  values.i11.TYPE[0] = _i11; \
  values.i12.TYPE[0] = _i12; \
  values.i13.TYPE[0] = _i13; \
  values.i14.TYPE[0] = _i14; \
  values.i15.TYPE[0] = _i15; \
  values.i16.TYPE[0] = _i16; \
  values.i17.TYPE[0] = _i17; \
  values.i18.TYPE[0] = _i18; \
  values.i19.TYPE[0] = _i19; \
  WRAP_CALL(_func1) (_i0, _i1, _i2, _i3, _i4, _i5, _i6, _i7, _i8, \
		     _i9, _i10, _i11, _i12, _i13, _i14, _i15, _i16, \
		     _i17, _i18, _i19); \
  clear_float_registers; \
  fregs.F0.TYPE[0] = _i0; \
  fregs.F1.TYPE[0] = _i1; \
  fregs.F2.TYPE[0] = _i2; \
  fregs.F3.TYPE[0] = _i3; \
  fregs.F4.TYPE[0] = _i4; \
  fregs.F5.TYPE[0] = _i5; \
  fregs.F6.TYPE[0] = _i6; \
  fregs.F7.TYPE[0] = _i7; \
  num_fregs = 8; \
  WRAP_CALL(_func2) (_i0, _i1, _i2, _i3, _i4, _i5, _i6, _i7, _i8, \
		     _i9, _i10, _i11, _i12, _i13, _i14, _i15, _i16, \
		     _i17, _i18, _i19);

volatile __bf16 bf1, bf2, bf3, bf4, bf5, bf6, bf7, bf8;

void
test_m128bf16_on_stack ()
{
  __m128bf16 x[8];
  int i;
  for (i = 0; i < 8; i++)
    x[i] = (__m128bf16) { bf1, bf2, bf3, bf4, bf5, bf6, bf7, bf8 };
  pass = "m128bf16-8";
  def_check_int_passing8 (x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7],
			  fun_check_passing_m128bf16_8_values,
			  fun_check_passing_m128bf16_8_regs, _m128bf16);
}

void
test_too_many_m128bf16 ()
{
  __m128bf16 x[20];
  int i;
  for (i = 0; i < 20; i++)
    x[i] = (__m128bf16) { bf1, bf2, bf3, bf4, bf5, bf6, bf7, bf8 };
  pass = "m128bf16-20";
  def_check_int_passing20 (x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7],
			   x[8], x[9], x[10], x[11], x[12], x[13], x[14],
			   x[15], x[16], x[17], x[18], x[19],
			   fun_check_passing_m128bf16_20_values,
			   fun_check_passing_m128bf16_20_regs, _m128bf16);
}

static void
do_test (void)
{
  test_m128bf16_on_stack ();
  test_too_many_m128bf16 ();
  if (failed)
    abort ();
}
