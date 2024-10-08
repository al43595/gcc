/* PR target/82524 */
/* { dg-do compile } */
/* { dg-options "-O2 -masm=att" } */
/* { dg-additional-options "-mregparm=3" { target ia32 } } */
/* { dg-final { scan-assembler-not "mov\[sz\]bl" } } */

struct S
{
  char pad1;
  char val;
  char pad2;
  char pad3;
};

struct S
test_plus (struct S a, struct S b, struct S c)
{ 
  a.val = b.val + c.val;

  return a;
}

/* { dg-final { scan-assembler "\[ \t\]addb" } } */

struct S
test_minus (struct S a, struct S b, struct S c)
{ 
  a.val = b.val - c.val;

  return a;
}

/* { dg-final { scan-assembler "\[ \t\]subb" } } */

struct S
test_and (struct S a, struct S b, struct S c)
{ 
  a.val = b.val & c.val;

  return a;
}

/* { dg-final { scan-assembler "\[ \t\]andb" } } */

struct S
test_or (struct S a, struct S b, struct S c)
{ 
  a.val = b.val | c.val;

  return a;
}

/* { dg-final { scan-assembler "\[ \t\]orb" } } */

struct S
test_xor (struct S a, struct S b, struct S c)
{ 
  a.val = b.val ^ c.val;

  return a;
}

/* { dg-final { scan-assembler "\[ \t\]xorb" } } */
