/* PR c/108986 */
/* { dg-do compile } */
/* { dg-options "-Wall" } */

void
foo (int a[static 7])
{
}

int
main ()
{
  foo ((int *) 0);	/* { dg-warning "argument 1 null where non-null expected" } */
}
