/* { dg-require-effective-target vect_int } */
/* { dg-additional-options "-fdump-tree-optimized" } */

#define SIGNEDNESS signed

#include "vect-avg-1.c"

/* { dg-final { scan-tree-dump "vect_recog_average_pattern: detected" "vect" } } */
/* { dg-final { scan-tree-dump {\.AVG_FLOOR} "vect" { target vect_avg_qi } } } */
/* { dg-final { scan-tree-dump-not {vector\([^\n]*short} "optimized" { target vect_avg_qi } } } */
/* { dg-final { scan-tree-dump-times "vectorized 1 loop" 1 "vect" { target vect_avg_qi } } } */
