/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zve32x -mabi=ilp32d -mrvv-vector-bits=scalable -fdump-tree-vect-details" } */

#include "template-1.h"

/* { dg-final { scan-tree-dump-times "vectorized 1 loops in function" 2 "vect" } } */
