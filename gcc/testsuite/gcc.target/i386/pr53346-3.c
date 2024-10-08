/* { dg-do compile } */
/* { dg-options "-msse2 -O2 -mno-sse3" } */
/* { dg-final { scan-assembler-times "shufps" 17 } } */

typedef float v4sf __attribute__((vector_size(16)));

v4sf
__attribute__((noipa))
foo (v4sf a, v4sf b)
{
  return __builtin_shufflevector (a, b, 1, 2, 5, 3);
}

v4sf
__attribute__((noipa))
foo1 (v4sf a, v4sf b)
{
  return __builtin_shufflevector (a, b, 1, 5, 2, 3);
}

v4sf
__attribute__((noipa))
foo2 (v4sf a, v4sf b)
{
  return __builtin_shufflevector (a, b, 1, 2, 3, 5);
}

v4sf
__attribute__((noipa))
foo3 (v4sf a, v4sf b)
{
  return __builtin_shufflevector (a, b, 1, 4, 5, 6);
}

v4sf
__attribute__((noipa))
foo4 (v4sf a, v4sf b)
{
  return __builtin_shufflevector (a, b, 3, 6, 7, 5);
}

v4sf
__attribute__((noipa))
foo5 (v4sf a, v4sf b)
{
  return __builtin_shufflevector (a, b, 2, 4, 7, 6);
}

v4sf
__attribute__((noipa))
foo6 (v4sf a, v4sf b)
{
  return __builtin_shufflevector (a, b, 2, 4, 3, 6);
}

v4sf
__attribute__((noipa))
foo7 (v4sf a, v4sf b)
{
  return __builtin_shufflevector (a, b, 2, 3, 4, 6);
}

v4sf
__attribute__((noipa))
foo8 (v4sf a, v4sf b)
{
  return __builtin_shufflevector (a, b, 2, 4, 6, 3);
}

