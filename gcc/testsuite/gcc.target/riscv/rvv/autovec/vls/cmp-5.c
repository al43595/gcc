/* { dg-do compile } */
/* { dg-options "-march=rv64gcv_zvfh_zvl4096b -mabi=lp64d -O3 -fno-schedule-insns -fno-schedule-insns2 -mrvv-max-lmul=m8 -fdump-tree-optimized" } */

#include "def.h"

DEF_OP_VV (lt, 1, int8_t, <)
DEF_OP_VV (lt, 2, int8_t, <)
DEF_OP_VV (lt, 4, int8_t, <)
DEF_OP_VV (lt, 8, int8_t, <)
DEF_OP_VV (lt, 16, int8_t, <)
DEF_OP_VV (lt, 32, int8_t, <)
DEF_OP_VV (lt, 64, int8_t, <)
DEF_OP_VV (lt, 128, int8_t, <)
DEF_OP_VV (lt, 256, int8_t, <)
DEF_OP_VV (lt, 512, int8_t, <)
DEF_OP_VV (lt, 1024, int8_t, <)
DEF_OP_VV (lt, 2048, int8_t, <)
DEF_OP_VV (lt, 4096, int8_t, <)

DEF_OP_VV (lt, 1, int16_t, <)
DEF_OP_VV (lt, 2, int16_t, <)
DEF_OP_VV (lt, 4, int16_t, <)
DEF_OP_VV (lt, 8, int16_t, <)
DEF_OP_VV (lt, 16, int16_t, <)
DEF_OP_VV (lt, 32, int16_t, <)
DEF_OP_VV (lt, 64, int16_t, <)
DEF_OP_VV (lt, 128, int16_t, <)
DEF_OP_VV (lt, 256, int16_t, <)
DEF_OP_VV (lt, 512, int16_t, <)
DEF_OP_VV (lt, 1024, int16_t, <)
DEF_OP_VV (lt, 2048, int16_t, <)

DEF_OP_VV (lt, 1, int32_t, <)
DEF_OP_VV (lt, 2, int32_t, <)
DEF_OP_VV (lt, 4, int32_t, <)
DEF_OP_VV (lt, 8, int32_t, <)
DEF_OP_VV (lt, 16, int32_t, <)
DEF_OP_VV (lt, 32, int32_t, <)
DEF_OP_VV (lt, 64, int32_t, <)
DEF_OP_VV (lt, 128, int32_t, <)
DEF_OP_VV (lt, 256, int32_t, <)
DEF_OP_VV (lt, 512, int32_t, <)
DEF_OP_VV (lt, 1024, int32_t, <)

DEF_OP_VV (lt, 1, int64_t, <)
DEF_OP_VV (lt, 2, int64_t, <)
DEF_OP_VV (lt, 4, int64_t, <)
DEF_OP_VV (lt, 8, int64_t, <)
DEF_OP_VV (lt, 16, int64_t, <)
DEF_OP_VV (lt, 32, int64_t, <)
DEF_OP_VV (lt, 64, int64_t, <)
DEF_OP_VV (lt, 128, int64_t, <)
DEF_OP_VV (lt, 256, int64_t, <)
DEF_OP_VV (lt, 512, int64_t, <)

DEF_OP_VV (lt, 1, _Float16, <)
DEF_OP_VV (lt, 2, _Float16, <)
DEF_OP_VV (lt, 4, _Float16, <)
DEF_OP_VV (lt, 8, _Float16, <)
DEF_OP_VV (lt, 16, _Float16, <)
DEF_OP_VV (lt, 32, _Float16, <)
DEF_OP_VV (lt, 64, _Float16, <)
DEF_OP_VV (lt, 128, _Float16, <)
DEF_OP_VV (lt, 256, _Float16, <)
DEF_OP_VV (lt, 512, _Float16, <)
DEF_OP_VV (lt, 1024, _Float16, <)
DEF_OP_VV (lt, 2048, _Float16, <)

DEF_OP_VV (lt, 1, float, <)
DEF_OP_VV (lt, 2, float, <)
DEF_OP_VV (lt, 4, float, <)
DEF_OP_VV (lt, 8, float, <)
DEF_OP_VV (lt, 16, float, <)
DEF_OP_VV (lt, 32, float, <)
DEF_OP_VV (lt, 64, float, <)
DEF_OP_VV (lt, 128, float, <)
DEF_OP_VV (lt, 256, float, <)
DEF_OP_VV (lt, 512, float, <)
DEF_OP_VV (lt, 1024, float, <)

DEF_OP_VV (lt, 1, double, <)
DEF_OP_VV (lt, 2, double, <)
DEF_OP_VV (lt, 4, double, <)
DEF_OP_VV (lt, 8, double, <)
DEF_OP_VV (lt, 16, double, <)
DEF_OP_VV (lt, 32, double, <)
DEF_OP_VV (lt, 64, double, <)
DEF_OP_VV (lt, 128, double, <)
DEF_OP_VV (lt, 256, double, <)
DEF_OP_VV (lt, 512, double, <)

/* { dg-final { scan-assembler-times {vmslt\.vv} 40 } } */
/* { dg-final { scan-assembler-times {vmflt\.vv} 27 } } */
/* { dg-final { scan-assembler-not {csrr} } } */
/* { dg-final { scan-tree-dump-not "1,1" "optimized" } } */
/* { dg-final { scan-tree-dump-not "2,2" "optimized" } } */
/* { dg-final { scan-tree-dump-not "4,4" "optimized" } } */
/* { dg-final { scan-tree-dump-not "16,16" "optimized" } } */
/* { dg-final { scan-tree-dump-not "32,32" "optimized" } } */
/* { dg-final { scan-tree-dump-not "64,64" "optimized" } } */
/* { dg-final { scan-tree-dump-not "128,128" "optimized" } } */
/* { dg-final { scan-tree-dump-not "256,256" "optimized" } } */
/* { dg-final { scan-tree-dump-not "512,512" "optimized" } } */
/* { dg-final { scan-tree-dump-not "1024,1024" "optimized" } } */
/* { dg-final { scan-tree-dump-not "2048,2048" "optimized" } } */
/* { dg-final { scan-tree-dump-not "4096,4096" "optimized" } } */
