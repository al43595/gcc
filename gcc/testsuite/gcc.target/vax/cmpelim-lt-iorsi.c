/* { dg-do compile } */
/* { dg-options "-fdump-rtl-cmpelim -dp" } */
/* { dg-skip-if "code quality test" { *-*-* } { "-O0" } { "" } } */

typedef int __attribute__ ((mode (SI))) int_t;

int_t
lt_iorsi (int_t x, int_t y)
{
  x |= y;
  if (x < 0)
    return x;
  else
    return x + 2;
}

/* Expect assembly like:

	bisl3 8(%ap),4(%ap),%r0		# 29	[c=28]  *iorsi3_ccn/2
	jlss .L1			# 31	[c=26]  *branch_ccn
	addl2 $2,%r0			# 28	[c=32]  *addsi3
.L1:

 */

/* { dg-final { scan-rtl-dump-times "deleting insn with uid" 1 "cmpelim" } } */
/* { dg-final { scan-assembler-not "\t(bit|cmpz?|tst). " } } */
/* { dg-final { scan-assembler "iorsi\[^ \]*_ccn(/\[0-9\]+)?\n" } } */
/* { dg-final { scan-assembler "branch_ccn\n" } } */
