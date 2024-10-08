/* { dg-do compile { target aarch64*-*-* } } */
/* { dg-options "-flax-vector-conversions" } */

typedef int v4si __attribute__((vector_size(16)));
typedef short v8hi __attribute__((vector_size(16)));

struct s { __Int16x8_t x; __Int32x4_t y; };
union u1 { __Int16x8_t x; __Int32x4_t y; };
union u2 { __Int32x4_t s; __Int16x8_t y; };

void
foo (v4si i, v8hi h)
{
  struct s x1 = { i, i };
  struct s x2 = { h, h };
  struct s x3 = { i, h };
  struct s x4 = { h, i };

  union u1 y1 = { i };
  union u1 y2 = { h };
  union u2 y3 = { i };
  union u2 y4 = { h };

  v4si z1[] = { i, i };
  v4si z2[] = { i, h };
  v4si z3[] = { h, i };
  v4si z4[] = { h, h };
  v8hi z5[] = { i, i };
  v8hi z6[] = { i, h };
  v8hi z7[] = { h, i };
  v8hi z8[] = { h, h };
}
