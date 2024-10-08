/* { dg-options "-mlasx -w -fno-strict-aliasing" } */
#include "../simd_correctness_check.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_op0, __m256i_op1, __m256i_op2, __m256i_out, __m256i_result;
  __m256 __m256_op0, __m256_op1, __m256_op2, __m256_out, __m256_result;
  __m256d __m256d_op0, __m256d_op1, __m256d_op2, __m256d_out, __m256d_result;

  int int_op0, int_op1, int_op2, int_out, int_result, i = 1, fail;
  long int long_op0, long_op1, long_op2, lont_out, lont_result;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000017;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000001700170017;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000017;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000001700170017;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000017;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000001700170017;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000017;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000001700170017;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsubwev_h_bu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x00007f7f00007f7f;
  *((unsigned long *)&__m256i_op0[2]) = 0x00007f7f00007f7f;
  *((unsigned long *)&__m256i_op0[1]) = 0x00007f7f00007f7f;
  *((unsigned long *)&__m256i_op0[0]) = 0x00007f7f00007f7f;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[0]) = 0xffffffff00000001;
  *((unsigned long *)&__m256i_result[3]) = 0x0000007f0000007f;
  *((unsigned long *)&__m256i_result[2]) = 0x0000007f0000007f;
  *((unsigned long *)&__m256i_result[1]) = 0xff01ff80ff01ff80;
  *((unsigned long *)&__m256i_result[0]) = 0xff01ff800000007e;
  __m256i_out = __lasx_xvsubwev_h_bu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x2020202020202020;
  *((unsigned long *)&__m256i_op0[2]) = 0x2020202020206431;
  *((unsigned long *)&__m256i_op0[1]) = 0x2020202020202020;
  *((unsigned long *)&__m256i_op0[0]) = 0x2020202020206431;
  *((unsigned long *)&__m256i_op1[3]) = 0x0043030300400300;
  *((unsigned long *)&__m256i_op1[2]) = 0x0043030300400300;
  *((unsigned long *)&__m256i_op1[1]) = 0x0043030300400100;
  *((unsigned long *)&__m256i_op1[0]) = 0x0043030300400100;
  *((unsigned long *)&__m256i_result[3]) = 0xffdd001dffe00020;
  *((unsigned long *)&__m256i_result[2]) = 0xffdd001dffe00031;
  *((unsigned long *)&__m256i_result[1]) = 0xffdd001dffe00020;
  *((unsigned long *)&__m256i_result[0]) = 0xffdd001dffe00031;
  __m256i_out = __lasx_xvsubwev_h_bu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xfffffe20001dfe1f;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0xfffffe20001dfe1f;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x000000001ffe2000;
  *((unsigned long *)&__m256i_op1[2]) = 0x001fe020001fe020;
  *((unsigned long *)&__m256i_op1[1]) = 0x000000001ffe2000;
  *((unsigned long *)&__m256i_op1[0]) = 0x001fe020001fe020;
  *((unsigned long *)&__m256i_result[3]) = 0x00ff0020ff1f001f;
  *((unsigned long *)&__m256i_result[2]) = 0xffe1ffe0ffe1ffe0;
  *((unsigned long *)&__m256i_result[1]) = 0x00ff0020ff1f001f;
  *((unsigned long *)&__m256i_result[0]) = 0xffe1ffe0ffe1ffe0;
  __m256i_out = __lasx_xvsubwev_h_bu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0xffffffffffee00ba;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0xffffffffffee00ba;
  *((unsigned long *)&__m256i_op1[3]) = 0x8000800080008000;
  *((unsigned long *)&__m256i_op1[2]) = 0x80008000fff98000;
  *((unsigned long *)&__m256i_op1[1]) = 0x8000800080008000;
  *((unsigned long *)&__m256i_op1[0]) = 0x80008000fff98000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x00ff00fffff500ba;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x00ff00fffff500ba;
  __m256i_out = __lasx_xvsubwev_h_bu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x000000004efffe00;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000047000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x000000004efffe00;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000047000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000ffff00000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x000000000000ffff;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000ffff00000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x000000000000ffff;
  *((unsigned long *)&__m256i_result[3]) = 0x0000ff0100ff0000;
  *((unsigned long *)&__m256i_result[2]) = 0x000000000000ff01;
  *((unsigned long *)&__m256i_result[1]) = 0x0000ff0100ff0000;
  *((unsigned long *)&__m256i_result[0]) = 0x000000000000ff01;
  __m256i_out = __lasx_xvsubwev_h_bu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[0]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[3]) = 0xff01ff01ff01ff01;
  *((unsigned long *)&__m256i_result[2]) = 0xff01ff01ff01ff01;
  *((unsigned long *)&__m256i_result[1]) = 0xff01ff01ff01ff01;
  *((unsigned long *)&__m256i_result[0]) = 0xff01ff01ff01ff01;
  __m256i_out = __lasx_xvsubwev_h_bu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsubwev_w_hu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xfffcfffcfffcfffc;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0xfffcfffcfffcfffc;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000fffc0000fffc;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000fffc0000fffc;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsubwev_w_hu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0001504f4c4b2361;
  *((unsigned long *)&__m256i_op0[2]) = 0x303338a48f374969;
  *((unsigned long *)&__m256i_op0[1]) = 0x0001504f4c4b2361;
  *((unsigned long *)&__m256i_op0[0]) = 0x303338a48f374969;
  *((unsigned long *)&__m256i_op1[3]) = 0x00000000f0f0f0f0;
  *((unsigned long *)&__m256i_op1[2]) = 0xf0f0f0f0f0f0f0f0;
  *((unsigned long *)&__m256i_op1[1]) = 0x00000000f0f0f0f0;
  *((unsigned long *)&__m256i_op1[0]) = 0xf0f0f0f0f0f0f0f0;
  *((unsigned long *)&__m256i_result[3]) = 0x0000504fffff3271;
  *((unsigned long *)&__m256i_result[2]) = 0xffff47b4ffff5879;
  *((unsigned long *)&__m256i_result[1]) = 0x0000504fffff3271;
  *((unsigned long *)&__m256i_result[0]) = 0xffff47b4ffff5879;
  __m256i_out = __lasx_xvsubwev_w_hu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[2]) = 0xffff0000ffff0001;
  *((unsigned long *)&__m256i_op0[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[0]) = 0xffff0000ffff0001;
  *((unsigned long *)&__m256i_op1[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[2]) = 0xffff0000ffff0001;
  *((unsigned long *)&__m256i_op1[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[0]) = 0xffff0000ffff0001;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsubwev_w_hu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x00000000000000f0;
  *((unsigned long *)&__m256i_op0[1]) = 0x00000000000000f0;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x4000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x4000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x4000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x4000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x00000000000000f0;
  *((unsigned long *)&__m256i_result[1]) = 0x00000000000000f0;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsubwev_w_hu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[2]) = 0xffffffff00000000;
  *((unsigned long *)&__m256i_op0[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[0]) = 0xffffffff00000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000ffff0000ffff;
  *((unsigned long *)&__m256i_result[2]) = 0x0000ffff00000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000ffff0000ffff;
  *((unsigned long *)&__m256i_result[0]) = 0x0000ffff00000000;
  __m256i_out = __lasx_xvsubwev_w_hu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xfffffffffffffffe;
  *((unsigned long *)&__m256i_op0[2]) = 0xfffffffefffffefc;
  *((unsigned long *)&__m256i_op0[1]) = 0xfffffffffffffffe;
  *((unsigned long *)&__m256i_op0[0]) = 0xfffffffffffffffe;
  *((unsigned long *)&__m256i_op1[3]) = 0xfffffffffffffff8;
  *((unsigned long *)&__m256i_op1[2]) = 0xfffffffffffffbf4;
  *((unsigned long *)&__m256i_op1[1]) = 0xfffffffffffffffc;
  *((unsigned long *)&__m256i_op1[0]) = 0xfffffffffffffffc;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000006;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000308;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000002;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000002;
  __m256i_out = __lasx_xvsubwev_d_wu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[0]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000010100000102;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000010100000102;
  *((unsigned long *)&__m256i_result[3]) = 0x00000000ffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0x00000000fffffefd;
  *((unsigned long *)&__m256i_result[1]) = 0x00000000ffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0x00000000fffffefd;
  __m256i_out = __lasx_xvsubwev_d_wu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x00000000ffffffff;
  *((unsigned long *)&__m256i_op0[2]) = 0x00000000ffff8c80;
  *((unsigned long *)&__m256i_op0[1]) = 0x00000000ffffffff;
  *((unsigned long *)&__m256i_op0[0]) = 0x00000000fffffe40;
  *((unsigned long *)&__m256i_op1[3]) = 0x80000000ffffffff;
  *((unsigned long *)&__m256i_op1[2]) = 0x80000000ffff8c80;
  *((unsigned long *)&__m256i_op1[1]) = 0x80000000ffffffff;
  *((unsigned long *)&__m256i_op1[0]) = 0x80000000fff0e400;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x00000000000f1a40;
  __m256i_out = __lasx_xvsubwev_d_wu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x00000000003effe1;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x00000000003effe1;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x00000000003effe1;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x00000000003effe1;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsubwev_d_wu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0001fffe0000ffff;
  *((unsigned long *)&__m256i_op0[2]) = 0x0001fffe00010001;
  *((unsigned long *)&__m256i_op0[1]) = 0x0001fffe0000ffff;
  *((unsigned long *)&__m256i_op0[0]) = 0x0001fffe00010001;
  *((unsigned long *)&__m256i_op1[3]) = 0x0001fffe0000ffff;
  *((unsigned long *)&__m256i_op1[2]) = 0x0001fffe00010001;
  *((unsigned long *)&__m256i_op1[1]) = 0x0001fffe0000ffff;
  *((unsigned long *)&__m256i_op1[0]) = 0x0001fffe00010001;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsubwev_d_wu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[0]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000008;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000008;
  *((unsigned long *)&__m256i_result[3]) = 0x00000000ffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0x00000000fffffff7;
  *((unsigned long *)&__m256i_result[1]) = 0x00000000ffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0x00000000fffffff7;
  __m256i_out = __lasx_xvsubwev_d_wu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x000000000000fffe;
  *((unsigned long *)&__m256i_op1[2]) = 0x000000000000fffe;
  *((unsigned long *)&__m256i_op1[1]) = 0x000000000000fffe;
  *((unsigned long *)&__m256i_op1[0]) = 0x000000000000fffe;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffff0002;
  *((unsigned long *)&__m256i_result[2]) = 0xffffffffffff0002;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffff0002;
  *((unsigned long *)&__m256i_result[0]) = 0xffffffffffff0002;
  __m256i_out = __lasx_xvsubwev_d_wu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsubwev_d_wu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[2]) = 0xffffffffffff0000;
  *((unsigned long *)&__m256i_op0[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op0[0]) = 0xffffffffffff0000;
  *((unsigned long *)&__m256i_op1[3]) = 0x7fffffffffffffff;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x7fffffffffffffff;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x00000000ffff0000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x00000000ffff0000;
  __m256i_out = __lasx_xvsubwev_d_wu (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsubwev_q_du (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsubwev_q_du (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x5d20a0a15d20a0a1;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x5d20a0a15d20a0a1;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000000;
  __m256i_out = __lasx_xvsubwev_q_du (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000100000000;
  *((unsigned long *)&__m256i_op1[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[2]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_op1[0]) = 0xffffff00ffffffff;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000001;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0x0000010000000001;
  __m256i_out = __lasx_xvsubwev_q_du (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[3]) = 0x1c1c1c1c1c1c1c1c;
  *((unsigned long *)&__m256i_op1[2]) = 0xfffffffeffffff00;
  *((unsigned long *)&__m256i_op1[1]) = 0x1c1c1c1c1c1c1c1c;
  *((unsigned long *)&__m256i_op1[0]) = 0xfffffffeffffff00;
  *((unsigned long *)&__m256i_result[3]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000100000100;
  *((unsigned long *)&__m256i_result[1]) = 0xffffffffffffffff;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000100000100;
  __m256i_out = __lasx_xvsubwev_q_du (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  *((unsigned long *)&__m256i_op0[3]) = 0x0040000000000003;
  *((unsigned long *)&__m256i_op0[2]) = 0x0000000000000003;
  *((unsigned long *)&__m256i_op0[1]) = 0x0040000000000003;
  *((unsigned long *)&__m256i_op0[0]) = 0x0000000000000003;
  *((unsigned long *)&__m256i_op1[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[2]) = 0x0000000000000002;
  *((unsigned long *)&__m256i_op1[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_op1[0]) = 0x0000000000000002;
  *((unsigned long *)&__m256i_result[3]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[2]) = 0x0000000000000001;
  *((unsigned long *)&__m256i_result[1]) = 0x0000000000000000;
  *((unsigned long *)&__m256i_result[0]) = 0x0000000000000001;
  __m256i_out = __lasx_xvsubwev_q_du (__m256i_op0, __m256i_op1);
  ASSERTEQ_64 (__LINE__, __m256i_result, __m256i_out);

  return 0;
}
