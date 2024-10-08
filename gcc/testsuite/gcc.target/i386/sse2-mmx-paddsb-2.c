/* { dg-do compile } */
/* { dg-options "-O2 -msse2" } */

typedef char v8qi __attribute__ ((vector_size (8)));

char foo()
{
  v8qi tx = { 1, 0, 0, 0, 0, 0, 0, 0 };
  v8qi ty = { 2, 0, 0, 0, 0, 0, 0, 0 };
  v8qi t = __builtin_ia32_paddsb(tx, ty);
  return t[0];
}

char bar()
{
  v8qi tx = { 100, 0, 0, 0, 0, 0, 0, 0 };
  v8qi ty = { 100, 0, 0, 0, 0, 0, 0, 0 };
  v8qi t = __builtin_ia32_paddsb(tx, ty);
  return t[0];
}

char baz()
{
  v8qi tx = { -100, 0, 0, 0, 0, 0, 0, 0 };
  v8qi ty = { -100, 0, 0, 0, 0, 0, 0, 0 };
  v8qi t = __builtin_ia32_paddsb(tx, ty);
  return t[0];
}

/* { dg-final { scan-assembler-times "movl\[ \\t\]+\\\$3," 1 } } */
/* { dg-final { scan-assembler-times "movl\[ \\t\]+\\\$127," 1 } } */
/* { dg-final { scan-assembler-times "movl\[ \\t\]+\\\$-?128," 1 } } */
/* { dg-final { scan-assembler-not "paddsb\[ \\t\]+%xmm\[0-9\]+" } } */
