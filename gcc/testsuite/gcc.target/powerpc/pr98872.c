/* PR target/98872 */
/* { dg-require-effective-target power10_ok } */
/* { dg-options "-O2 -mdejagnu-cpu=power10" } */

/* Verify we do not ICE on the following tests.  */

void
foo (__vector_quad *dst)
{
  __vector_quad acc;
  *dst = acc;
}

void
bar (__vector_pair *dst)
{
  __vector_pair pair;
  *dst = pair;
}
