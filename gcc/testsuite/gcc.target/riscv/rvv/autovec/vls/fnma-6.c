/* { dg-do compile } */
/* { dg-options "-march=rv64gcv_zvfh_zvl4096b -mabi=lp64d -O3 -mrvv-max-lmul=m8 -fdump-tree-optimized" } */

#include "def.h"

DEF_FNMA_VV (fnma, 2, float)
DEF_FNMA_VV (fnma, 4, float)
DEF_FNMA_VV (fnma, 8, float)
DEF_FNMA_VV (fnma, 16, float)
DEF_FNMA_VV (fnma, 32, float)
DEF_FNMA_VV (fnma, 64, float)
DEF_FNMA_VV (fnma, 128, float)
DEF_FNMA_VV (fnma, 256, float)
DEF_FNMA_VV (fnma, 512, float)
DEF_FNMA_VV (fnma, 1024, float)

/* { dg-final { scan-assembler-times {vfnms[a-u][b-c]\.vv} 10 } } */
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
