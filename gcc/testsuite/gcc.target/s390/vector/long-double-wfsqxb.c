/* { dg-do compile } */
/* { dg-options "-O3 -march=z14 -mzarch" } */
#include "long-double-wf.h"

LONG_DOUBLE_WF (SQRTL);

/* { dg-final { scan-assembler {\n\twfsqxb\t} } } */
