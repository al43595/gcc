/* { dg-do assemble { target aarch64_asm_sve_ok } } */
/* { dg-options "-O -msve-vector-bits=2048 -save-temps" } */

#include <stdint.h>

#define TEST_SHIFT_IMM(TYPE, NAME, OP, AMT) \
  TYPE \
  NAME##_##TYPE##_##AMT (TYPE a, TYPE b, TYPE c) \
  { \
    return a ? b OP AMT : c; \
  }

#define TEST_SHIFT(TYPE, NAME, OP, LIMIT) \
  TYPE \
  NAME##_##TYPE##_reg (TYPE a, TYPE b, TYPE c, TYPE d) \
  { \
    return a ? b OP c : d; \
  } \
  TEST_SHIFT_IMM (TYPE, NAME, OP, 1) \
  TEST_SHIFT_IMM (TYPE, NAME, OP, 5) \
  TEST_SHIFT_IMM (TYPE, NAME, OP, LIMIT)

#define TEST_TYPE(TYPE, SIZE, LIMIT) \
  typedef TYPE TYPE##SIZE __attribute__((vector_size(SIZE))); \
  TEST_SHIFT (TYPE##SIZE, shl, <<, LIMIT) \
  TEST_SHIFT (TYPE##SIZE, shr, >>, LIMIT) \

TEST_TYPE (int8_t, 32, 7)
TEST_TYPE (uint8_t, 32, 7)

TEST_TYPE (int8_t, 64, 7)
TEST_TYPE (uint8_t, 64, 7)
TEST_TYPE (int16_t, 64, 15)
TEST_TYPE (uint16_t, 64, 15)

TEST_TYPE (int8_t, 128, 7)
TEST_TYPE (uint8_t, 128, 7)
TEST_TYPE (int16_t, 128, 15)
TEST_TYPE (uint16_t, 128, 15)
TEST_TYPE (int32_t, 128, 31)
TEST_TYPE (uint32_t, 128, 31)

/* { dg-final { scan-assembler-times {\tlsl\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b, z[0-9]+\.b\n} 6 } } */
/* { dg-final { scan-assembler-times {\tlsl\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h, z[0-9]+\.h\n} 4 } } */
/* { dg-final { scan-assembler-times {\tlsl\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, z[0-9]+\.s\n} 2 } } */

/* { dg-final { scan-assembler-times {\tlsr\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b, z[0-9]+\.b\n} 3 } } */
/* { dg-final { scan-assembler-times {\tlsr\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h, z[0-9]+\.h\n} 2 } } */
/* { dg-final { scan-assembler-times {\tlsr\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, z[0-9]+\.s\n} 1 } } */

/* { dg-final { scan-assembler-times {\tasr\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b, z[0-9]+\.b\n} 3 } } */
/* { dg-final { scan-assembler-times {\tasr\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h, z[0-9]+\.h\n} 2 } } */
/* { dg-final { scan-assembler-times {\tasr\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, z[0-9]+\.s\n} 1 } } */

/* { dg-final { scan-assembler-times {\tlsl\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b, #1\n} 6 } } */
/* { dg-final { scan-assembler-times {\tlsl\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h, #1\n} 4 } } */
/* { dg-final { scan-assembler-times {\tlsl\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #1\n} 2 } } */

/* { dg-final { scan-assembler-times {\tlsr\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b, #1\n} 3 } } */
/* { dg-final { scan-assembler-times {\tlsr\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h, #1\n} 2 } } */
/* { dg-final { scan-assembler-times {\tlsr\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #1\n} 1 } } */

/* { dg-final { scan-assembler-times {\tasr\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b, #1\n} 3 } } */
/* { dg-final { scan-assembler-times {\tasr\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h, #1\n} 2 } } */
/* { dg-final { scan-assembler-times {\tasr\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #1\n} 1 } } */

/* { dg-final { scan-assembler-times {\tlsl\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b, #5\n} 6 } } */
/* { dg-final { scan-assembler-times {\tlsl\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h, #5\n} 4 } } */
/* { dg-final { scan-assembler-times {\tlsl\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #5\n} 2 } } */

/* { dg-final { scan-assembler-times {\tlsr\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b, #5\n} 3 } } */
/* { dg-final { scan-assembler-times {\tlsr\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h, #5\n} 2 } } */
/* { dg-final { scan-assembler-times {\tlsr\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #5\n} 1 } } */

/* { dg-final { scan-assembler-times {\tasr\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b, #5\n} 3 } } */
/* { dg-final { scan-assembler-times {\tasr\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h, #5\n} 2 } } */
/* { dg-final { scan-assembler-times {\tasr\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #5\n} 1 } } */

/* { dg-final { scan-assembler-times {\tlsl\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b, #7\n} 6 } } */
/* { dg-final { scan-assembler-times {\tlsl\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h, #15\n} 4 } } */
/* { dg-final { scan-assembler-times {\tlsl\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #31\n} 2 } } */

/* { dg-final { scan-assembler-times {\tlsr\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b, #7\n} 3 } } */
/* { dg-final { scan-assembler-times {\tlsr\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h, #15\n} 2 } } */
/* { dg-final { scan-assembler-times {\tlsr\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #31\n} 1 } } */

/* { dg-final { scan-assembler-times {\tasr\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b, #7\n} 3 } } */
/* { dg-final { scan-assembler-times {\tasr\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h, #15\n} 2 } } */
/* { dg-final { scan-assembler-times {\tasr\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #31\n} 1 } } */

/* { dg-final { scan-assembler-times {\tmovprfx\tz[0-9]+\.b, p[0-7]/m, z[0-9]+\.b\n} 48 } } */
/* { dg-final { scan-assembler-times {\tmovprfx\tz[0-9]+\.h, p[0-7]/m, z[0-9]+\.h\n} 32 } } */
/* { dg-final { scan-assembler-times {\tmovprfx\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s\n} 16 } } */
/* { dg-final { scan-assembler-not {\tsel\t} } } */
