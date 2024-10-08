/* { dg-do run } */

typedef long int_t;

__attribute__ ((noinline)) int_t
movlfge (double w, double x, int_t y, int_t z)
{
  return w >= x ? y : z;
}

int
main (void)
{
  if (movlfge (-1.0, -1.0, 12L, 23L) != 12L)
    return 1;
  if (movlfge (-1.0, 3.0, 12L, 23L) != 23L)
    return 1;
  if (movlfge (1.0, 3.0, 12L, 23L) != 23L)
    return 1;
  if (movlfge (3.0, 3.0, 12L, 23L) != 12L)
    return 1;
  if (movlfge (5.0, 3.0, 12L, 23L) != 12L)
    return 1;
  if (movlfge (3.0, -1.0, 12L, 23L) != 12L)
    return 1;
  if (movlfge (3.0, 1.0, 12L, 23L) != 12L)
    return 1;
  if (movlfge (3.0, 5.0, 12L, 23L) != 23L)
    return 1;
  return 0;
}
