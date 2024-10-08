/* { dg-do compile } */
/* { dg-options "-fdump-rtl-cmpelim -dp" } */
/* { dg-skip-if "code quality test" { *-*-* } { "-O0" "-O1" } { "" } } */

typedef int __attribute__ ((mode (QI))) int_t;

void
le_subqi (int_t *w, int_t *x, int_t *y)
{
  int_t v;

  v = *x - *y;
  if (v <= 0)
    *w = v;
  else
    *w = v + 2;
}

/* Expect assembly like:

	subb3 *12(%ap),*8(%ap),%r0	# 29	[c=64]  *subqi3_ccnz/1
	jleq .L2			# 31	[c=26]  *branch_ccnz
	addb2 $2,%r0			# 28	[c=32]  *addqi3
.L2:

 */

/* { dg-final { scan-rtl-dump-times "deleting insn with uid" 1 "cmpelim" } } */
/* { dg-final { scan-assembler-not "\t(bit|cmpz?|tst). " } } */
/* { dg-final { scan-assembler "subqi\[^ \]*_ccnz(/\[0-9\]+)?\n" } } */
/* { dg-final { scan-assembler "branch_ccnz\n" } } */
