#include <arm_neon.h>
#include "arm-neon-ref.h"
#include "compute-ref-data.h"

/* Expected results.  */
VECT_VAR_DECL(expected,int,8,8) [] = { 0xf8, 0xf9, 0xf9, 0xfa,
				       0xfa, 0xfb, 0xfb, 0xfc };
VECT_VAR_DECL(expected,int,16,4) [] = { 0xfff8, 0xfff9, 0xfff9, 0xfffa };
VECT_VAR_DECL(expected,int,32,2) [] = { 0xfffffffc, 0xfffffffc };
VECT_VAR_DECL(expected,uint,8,8) [] = { 0xff, 0xff, 0xff, 0xff,
					0xff, 0xff, 0xff, 0xff };
VECT_VAR_DECL(expected,uint,16,4) [] = { 0xffff, 0xffff, 0xffff, 0xffff };
VECT_VAR_DECL(expected,uint,32,2) [] = { 0xffffffff, 0xffffffff };

/* Expected results with shift by 3.  */
VECT_VAR_DECL(expected_sh3,int,8,8) [] = { 0x7f, 0x7f, 0x7f, 0x7f,
					   0x7f, 0x7f, 0x7f, 0x7f };
VECT_VAR_DECL(expected_sh3,int,16,4) [] = { 0x7fff, 0x7fff, 0x7fff, 0x7fff };
VECT_VAR_DECL(expected_sh3,int,32,2) [] = { 0x7fffffff, 0x7fffffff };
VECT_VAR_DECL(expected_sh3,uint,8,8) [] = { 0xff, 0xff, 0xff, 0xff,
					    0xff, 0xff, 0xff, 0xff };
VECT_VAR_DECL(expected_sh3,uint,16,4) [] = { 0xffff, 0xffff, 0xffff, 0xffff };
VECT_VAR_DECL(expected_sh3,uint,32,2) [] = { 0xffffffff, 0xffffffff };

/* Expected results with shift by max amount.  */
VECT_VAR_DECL(expected_shmax,int,8,8) [] = { 0x7f, 0x7f, 0x7f, 0x7f,
					     0x7f, 0x7f, 0x7f, 0x7f };
VECT_VAR_DECL(expected_shmax,int,16,4) [] = { 0x7fff, 0x7fff, 0x7fff, 0x7fff };
VECT_VAR_DECL(expected_shmax,int,32,2) [] = { 0x7fffffff, 0x7fffffff };
VECT_VAR_DECL(expected_shmax,uint,8,8) [] = { 0xff, 0xff, 0xff, 0xff,
					      0xff, 0xff, 0xff, 0xff };
VECT_VAR_DECL(expected_shmax,uint,16,4) [] = { 0xffff, 0xffff, 0xffff, 0xffff };
VECT_VAR_DECL(expected_shmax,uint,32,2) [] = { 0xffffffff, 0xffffffff };

#define INSN vqrshrn_n
#define TEST_MSG "VQRSHRN_N"

#define FNNAME1(NAME) void exec_ ## NAME (void)
#define FNNAME(NAME) FNNAME1(NAME)

FNNAME (INSN)
{
  /* Basic test: y=vqrshrn_n(x,v), then store the result.  */
#define TEST_VQRSHRN_N2(INSN, T1, T2, W, W2, N, V, CMT) \
  Set_Neon_Cumulative_Sat(0, VECT_VAR(vector_res, T1, W2, N));		\
  VECT_VAR(vector_res, T1, W2, N) =					\
    INSN##_##T2##W(VECT_VAR(vector, T1, W, N),				\
		   V);							\
  vst1_##T2##W2(VECT_VAR(result, T1, W2, N),				\
		VECT_VAR(vector_res, T1, W2, N))

  /* Two auxliary macros are necessary to expand INSN */
#define TEST_VQRSHRN_N1(INSN, T1, T2, W, W2, N, V, CMT) \
  TEST_VQRSHRN_N2(INSN, T1, T2, W, W2, N, V, CMT)

#define TEST_VQRSHRN_N(T1, T2, W, W2, N, V, CMT) \
  TEST_VQRSHRN_N1(INSN, T1, T2, W, W2, N, V, CMT)


  /* vector is twice as large as vector_res.  */
  DECL_VARIABLE(vector, int, 16, 8);
  DECL_VARIABLE(vector, int, 32, 4);
  DECL_VARIABLE(vector, int, 64, 2);
  DECL_VARIABLE(vector, uint, 16, 8);
  DECL_VARIABLE(vector, uint, 32, 4);
  DECL_VARIABLE(vector, uint, 64, 2);

  DECL_VARIABLE(vector_res, int, 8, 8);
  DECL_VARIABLE(vector_res, int, 16, 4);
  DECL_VARIABLE(vector_res, int, 32, 2);
  DECL_VARIABLE(vector_res, uint, 8, 8);
  DECL_VARIABLE(vector_res, uint, 16, 4);
  DECL_VARIABLE(vector_res, uint, 32, 2);

  clean_results ();

  VLOAD(vector, buffer, q, int, s, 16, 8);
  VLOAD(vector, buffer, q, int, s, 32, 4);
  VLOAD(vector, buffer, q, int, s, 64, 2);
  VLOAD(vector, buffer, q, uint, u, 16, 8);
  VLOAD(vector, buffer, q, uint, u, 32, 4);
  VLOAD(vector, buffer, q, uint, u, 64, 2);

  /* Choose shift amount arbitrarily.  */
#define CMT ""
  TEST_VQRSHRN_N(int, s, 16, 8, 8, 1, CMT);
  TEST_VQRSHRN_N(int, s, 32, 16, 4, 1, CMT);
  TEST_VQRSHRN_N(int, s, 64, 32, 2, 2, CMT);
  TEST_VQRSHRN_N(uint, u, 16, 8, 8, 2, CMT);
  TEST_VQRSHRN_N(uint, u, 32, 16, 4, 3, CMT);
  TEST_VQRSHRN_N(uint, u, 64, 32, 2, 3, CMT);

  CHECK(TEST_MSG, int, 8, 8, PRIx8, expected, CMT);
  CHECK(TEST_MSG, int, 16, 4, PRIx16, expected, CMT);
  CHECK(TEST_MSG, int, 32, 2, PRIx32, expected, CMT);
  CHECK(TEST_MSG, uint, 8, 8, PRIx8, expected, CMT);
  CHECK(TEST_MSG, uint, 16, 4, PRIx16, expected, CMT);
  CHECK(TEST_MSG, uint, 32, 2, PRIx32, expected, CMT);


  /* Another set of tests, shifting max value by 3.  */
  VDUP(vector, q, int, s, 16, 8, 0x7FFF);
  VDUP(vector, q, int, s, 32, 4, 0x7FFFFFFF);
  VDUP(vector, q, int, s, 64, 2, 0x7FFFFFFFFFFFFFFFLL);
  VDUP(vector, q, uint, u, 16, 8, 0xFFFF);
  VDUP(vector, q, uint, u, 32, 4, 0xFFFFFFFF);
  VDUP(vector, q, uint, u, 64, 2, 0xFFFFFFFFFFFFFFFFULL);

#undef CMT
#define CMT " (check saturation: shift by 3)"
  TEST_VQRSHRN_N(int, s, 16, 8, 8, 3, CMT);
  TEST_VQRSHRN_N(int, s, 32, 16, 4, 3, CMT);
  TEST_VQRSHRN_N(int, s, 64, 32, 2, 3, CMT);
  TEST_VQRSHRN_N(uint, u, 16, 8, 8, 3, CMT);
  TEST_VQRSHRN_N(uint, u, 32, 16, 4, 3, CMT);
  TEST_VQRSHRN_N(uint, u, 64, 32, 2, 3, CMT);

  CHECK(TEST_MSG, int, 8, 8, PRIx8, expected_sh3, CMT);
  CHECK(TEST_MSG, int, 16, 4, PRIx16, expected_sh3, CMT);
  CHECK(TEST_MSG, int, 32, 2, PRIx32, expected_sh3, CMT);
  CHECK(TEST_MSG, uint, 8, 8, PRIx8, expected_sh3, CMT);
  CHECK(TEST_MSG, uint, 16, 4, PRIx16, expected_sh3, CMT);
  CHECK(TEST_MSG, uint, 32, 2, PRIx32, expected_sh3, CMT);


  /* Shift by max amount.  */
#undef CMT
#define CMT " (check saturation: shift by max)"
  TEST_VQRSHRN_N(int, s, 16, 8, 8, 8, CMT);
  TEST_VQRSHRN_N(int, s, 32, 16, 4, 16, CMT);
  TEST_VQRSHRN_N(int, s, 64, 32, 2, 32, CMT);
  TEST_VQRSHRN_N(uint, u, 16, 8, 8, 8, CMT);
  TEST_VQRSHRN_N(uint, u, 32, 16, 4, 16, CMT);
  TEST_VQRSHRN_N(uint, u, 64, 32, 2, 32, CMT);

  CHECK(TEST_MSG, int, 8, 8, PRIx8, expected_shmax, CMT);
  CHECK(TEST_MSG, int, 16, 4, PRIx16, expected_shmax, CMT);
  CHECK(TEST_MSG, int, 32, 2, PRIx32, expected_shmax, CMT);
  CHECK(TEST_MSG, uint, 8, 8, PRIx8, expected_shmax, CMT);
  CHECK(TEST_MSG, uint, 16, 4, PRIx16, expected_shmax, CMT);
  CHECK(TEST_MSG, uint, 32, 2, PRIx32, expected_shmax, CMT);
}

int main (void)
{
  exec_vqrshrn_n ();
  return 0;
}
