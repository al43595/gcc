/* { dg-do compile } */
/* { dg-options "-O2 -fstack-clash-protection --param stack-clash-protection-guard-size=16 -fomit-frame-pointer -momit-leaf-frame-pointer -fno-stack-protector" } */
/* { dg-require-effective-target supports_stack_clash_protection } */

void
f (void)
{
  volatile int x[16384 + 1000];
  x[0] = 0;
}

/* { dg-final { scan-assembler-times {str\s+xzr, \[sp, 1024\]} 1 } } */

/* SIZE is more than 1 guard-size, but only one 64KB page is used, expect only 1
   probe.  Leaf function and omitting leaf pointers.  */
