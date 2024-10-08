/* { dg-do run } */
/* { dg-options "-O2 -mavxvnniint16" } */
/* { dg-require-effective-target avxvnniint16 } */
#define AVXVNNIINT16
#ifndef CHECK
#define CHECK "avx-check.h"
#endif

#ifndef TEST
#define TEST avx_test
#endif

#include CHECK

static void
CALC (unsigned int *r, unsigned int *dst, unsigned short *s1, unsigned short *s2, int size)
{
  unsigned int tempres[16];
  for (int i = 0; i < size; i++)
    tempres[i] = (unsigned int) s1[i] * (unsigned int) s2[i];
  for (int i = 0; i < size / 2; i++)
  {
    unsigned int test = (unsigned) dst[i] + tempres[i * 2] + tempres[i * 2 + 1];
    r[i] = test;
  }
}

void
TEST (void)
{
  int i;
  union256i_ud res_256;
  union256i_uw src1_256;
  union256i_uw src2_256;
  unsigned int res_ref_256[8];

  for (i = 0; i < 16; i++)
  {
    int sign = i % 2 ? 1 : -1;
    src1_256.a[i] = 10 + 3 * i + sign;
    src2_256.a[i] = sign * 10 * i * i;
  }

  for (i = 0; i < 8; i++)
    res_256.a[i] = 0x7fffffff;

  CALC (res_ref_256, res_256.a, src1_256.a, src2_256.a, 16);
  res_256.x = _mm256_dpwuud_avx_epi32 (res_256.x, src1_256.x, src2_256.x);
  if (check_union256i_ud (res_256, res_ref_256))
    abort ();

  union128i_ud res_128;
  union128i_uw src2_128;
  union128i_uw src1_128;
  unsigned int res_ref_128[4];

  for (i = 0; i < 8; i++)
  {
    int sign = i % 2 ? 1 : -1;
    src1_128.a[i] = 10 + 3 * i * i + sign;
    src2_128.a[i] = sign * 10 * i * i;
  }

  for (i = 0; i < 4; i++)
    res_128.a[i] = 0x7fffffff;

  CALC (res_ref_128, res_128.a, src1_128.a, src2_128.a, 8);
  res_128.x = _mm_dpwuud_avx_epi32 (res_128.x, src1_128.x, src2_128.x);
  if (check_union128i_ud (res_128, res_ref_128))
    abort ();
}
