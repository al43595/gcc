/* Test AAPCS layout (VFP variant) */

/* { dg-do run { target aarch64*-*-* } } */

#ifndef IN_FRAMEWORK
#define VFP
#define TESTFILE "test_dfp_8.c"

struct z
{
  _Decimal64 x[4];
};

struct z a = { 5.0dd, 6.0dd, 7.0dd, 8.0dd };
struct z b = { 9.0dd, 10.0dd, 11.0dd, 12.0dd };

#include "abitest.h"
#else
  ARG(struct z, a, D0)
  ARG(struct z, b, D4)
  ARG(_Decimal64, 0.5dd, STACK)
  ARG(int, 7, W0)
  LAST_ARG(int, 8, W1) 
#endif
