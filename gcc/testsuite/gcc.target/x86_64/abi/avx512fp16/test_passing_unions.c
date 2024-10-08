/* This tests passing of structs.  */

#include "avx512fp16-xmm-check.h"
#include "defines.h"
#include "args.h"

struct IntegerRegisters iregs;
struct FloatRegisters fregs;
unsigned int num_iregs, num_fregs;

struct int_struct
{
  int i;
};

struct long_struct
{
  long l;
};

union un1
{
  char c;
  int i;
};

union un2
{
  char c1;
  long l;
  char c2;
};

union un3
{
  struct int_struct is;
  struct long_struct ls;
  union un1 un;
};


void
check_union_passing1(union un1 u ATTRIBUTE_UNUSED)
{
  check_int_arguments;
}

void
check_union_passing2(union un2 u1 ATTRIBUTE_UNUSED)
{
  check_int_arguments;
}

void
check_union_passing3(union un3 u ATTRIBUTE_UNUSED)
{
  check_int_arguments;
}

#define check_union_passing1 WRAP_CALL(check_union_passing1)
#define check_union_passing2 WRAP_CALL(check_union_passing2)
#define check_union_passing3 WRAP_CALL(check_union_passing3)

#ifdef CHECK_M64_M128
union un4
{
  __m128 x;
  float f;
};

union un5
{
  __m128 x;
  long i;
};

void
check_union_passing4(union un4 u1 ATTRIBUTE_UNUSED,
		     union un4 u2 ATTRIBUTE_UNUSED,
		     union un4 u3 ATTRIBUTE_UNUSED,
		     union un4 u4 ATTRIBUTE_UNUSED,
		     union un4 u5 ATTRIBUTE_UNUSED,
		     union un4 u6 ATTRIBUTE_UNUSED,
		     union un4 u7 ATTRIBUTE_UNUSED,
		     union un4 u8 ATTRIBUTE_UNUSED)
{
  check_m128_arguments;
}

void
check_union_passing5(union un5 u ATTRIBUTE_UNUSED)
{
  check_int_arguments;
  check_vector_arguments(m128, 8);
}

union un4a
{
  __m128 x;
  _Float16 f;
};

void
check_union_passing4a(union un4a u1 ATTRIBUTE_UNUSED,
		      union un4a u2 ATTRIBUTE_UNUSED,
		      union un4a u3 ATTRIBUTE_UNUSED,
		      union un4a u4 ATTRIBUTE_UNUSED,
		      union un4a u5 ATTRIBUTE_UNUSED,
		      union un4a u6 ATTRIBUTE_UNUSED,
		      union un4a u7 ATTRIBUTE_UNUSED,
		      union un4a u8 ATTRIBUTE_UNUSED)
{
  check_m128_arguments;
}

union un4b
{
  __m128h x;
  _Float16 f;
};

void
check_union_passing4b(union un4b u1 ATTRIBUTE_UNUSED,
		      union un4b u2 ATTRIBUTE_UNUSED,
		      union un4b u3 ATTRIBUTE_UNUSED,
		      union un4b u4 ATTRIBUTE_UNUSED,
		      union un4b u5 ATTRIBUTE_UNUSED,
		      union un4b u6 ATTRIBUTE_UNUSED,
		      union un4b u7 ATTRIBUTE_UNUSED,
		      union un4b u8 ATTRIBUTE_UNUSED)
{
  check_m128_arguments;
}

#define check_union_passing4 WRAP_CALL(check_union_passing4)
#define check_union_passing4a WRAP_CALL(check_union_passing4a)
#define check_union_passing4b WRAP_CALL(check_union_passing4b)
#define check_union_passing5 WRAP_CALL(check_union_passing5)
#endif

union un6
{
  long double ld;
  int i;
};


void
check_union_passing6(union un6 u ATTRIBUTE_UNUSED)
{
  /* Check the passing on the stack by comparing the address of the
     stack elements to the expected place on the stack.  */
  assert ((unsigned long)&u.ld == rsp+8);
  assert ((unsigned long)&u.i == rsp+8);
}

#define check_union_passing6 WRAP_CALL(check_union_passing6)

union un7
{
  long double ld;
  _Float16 f;
};

void
check_union_passing7(union un7 u ATTRIBUTE_UNUSED)
{
  /* Check the passing on the stack by comparing the address of the
     stack elements to the expected place on the stack.  */
  assert ((unsigned long)&u.ld == rsp+8);
  assert ((unsigned long)&u.f == rsp+8);
}

#define check_union_passing7 WRAP_CALL(check_union_passing7)

union un8
{
  _Float16 f;
  int i;
};

void
check_union_passing8(union un8 u ATTRIBUTE_UNUSED)
{
  check_int_arguments;
}

#define check_union_passing8 WRAP_CALL(check_union_passing8)

static void
do_test (void)
{
  union un1 u1;
#ifdef CHECK_LARGER_UNION_PASSING
  union un2 u2;
  union un3 u3;
  struct int_struct is;
  struct long_struct ls;
#endif /* CHECK_LARGER_UNION_PASSING */
#ifdef CHECK_M64_M128
  union un4 u4[8];
  union un4a u4a[8];
  union un4b u4b[8];
  union un5 u5 = { { 48.394, 39.3, -397.9, 3484.9 } };
  int i;
#endif
  union un6 u6;
  union un7 u7;
  union un8 u8;

  /* Check a union with char, int.  */
  clear_struct_registers;
  u1.i = 0;  /* clear the struct to not have high bits left */
  u1.c = 32;
  iregs.I0 = 32;
  num_iregs = 1;
  clear_int_hardware_registers;
  check_union_passing1(u1);
  u1.i = 0;  /* clear the struct to not have high bits left */
  u1.i = 33;
  iregs.I0 = 33;
  num_iregs = 1;
  clear_int_hardware_registers;
  check_union_passing1(u1);

  /* Check a union with char, long, char.  */
#ifdef CHECK_LARGER_UNION_PASSING
  clear_struct_registers;
  u2.l = 0;  /* clear the struct to not have high bits left */
  u2.c1 = 34;
  iregs.I0 = 34;
  num_iregs = 1;
  clear_int_hardware_registers;
  check_union_passing2(u2);
  u2.l = 0;  /* clear the struct to not have high bits left */
  u2.l = 35;
  iregs.I0 = 35;
  num_iregs = 1;
  clear_int_hardware_registers;
  check_union_passing2(u2);
  u2.l = 0;  /* clear the struct to not have high bits left */
  u2.c2 = 36;
  iregs.I0 = 36;
  num_iregs = 1;
  clear_int_hardware_registers;
  check_union_passing2(u2);

  /* check a union containing two structs and a union.  */
  clear_struct_registers;
  is.i = 37;
  u3.ls.l = 0;  /* clear the struct to not have high bits left */
  u3.is = is;
  iregs.I0 = 37;
  num_iregs = 1;
  clear_int_hardware_registers;
  check_union_passing3(u3);
  ls.l = 38;
  u3.ls.l = 0;  /* clear the struct to not have high bits left */
  u3.ls = ls;
  iregs.I0 = 38;
  num_iregs = 1;
  clear_int_hardware_registers;
  check_union_passing3(u3);
  u1.c = 39;
  u3.ls.l = 0;  /* clear the struct to not have high bits left */
  u3.un = u1;
  iregs.I0 = 39;
  num_iregs = 1;
  clear_int_hardware_registers;
  check_union_passing3(u3);
  u1.i = 40;
  u3.ls.l = 0;  /* clear the struct to not have high bits left */
  u3.un = u1;
  iregs.I0 = 40;
  num_iregs = 1;
  clear_int_hardware_registers;
  check_union_passing3(u3);
#endif /* CHECK_LARGER_UNION_PASSING */

#ifdef CHECK_M64_M128
  clear_struct_registers;
  for (i = 0; i < 8; i++)
    {
      u4[i].x = (__m128){32+i, 0, i, 0};
      (&fregs.xmm0)[i]._m128[0] = u4[i].x;
    }
  num_fregs = 8;
  clear_float_hardware_registers;
  check_union_passing4(u4[0], u4[1], u4[2], u4[3],
		       u4[4], u4[5], u4[6], u4[7]);

  clear_struct_registers;
  for (i = 0; i < 8; i++)
    {
      u4a[i].x = (__m128){32+i, 0, i, 0};
      (&fregs.xmm0)[i]._m128[0] = u4[i].x;
    }
  num_fregs = 8;
  clear_float_hardware_registers;
  check_union_passing4a(u4a[0], u4a[1], u4a[2], u4a[3],
		       u4a[4], u4a[5], u4a[6], u4a[7]);

  clear_struct_registers;
  for (i = 0; i < 8; i++)
    {
      u4b[i].x = (__m128h){33+i, 0, i, 0, -i, 1, 2 * i, i + 8};
      (&fregs.xmm0)[i]._m128h[0] = u4b[i].x;
    }
  num_fregs = 8;
  clear_float_hardware_registers;
  check_union_passing4b(u4b[0], u4b[1], u4b[2], u4b[3],
		        u4b[4], u4b[5], u4b[6], u4b[7]);

  clear_struct_registers;
  fregs.xmm0._m128[0] = u5.x;
  num_fregs = 1;
  num_iregs = 1;
  iregs.I0 = u5.i;
  clear_float_hardware_registers;
  check_union_passing5(u5);
#endif

  u6.i = 2;
  check_union_passing6(u6);

  u7.f = 2.0f16;
  check_union_passing7(u7);

  clear_struct_registers;
  u8.i = 8;
  num_iregs = 1;
  iregs.I0 = u8.i;
  clear_int_hardware_registers;
  check_union_passing8(u8);
}
