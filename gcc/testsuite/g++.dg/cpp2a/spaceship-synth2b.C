// Test with only spaceship defaulted.
// { dg-do run { target c++20 } }

#include <compare>

struct D
{
  int i;
  friend auto operator<=>(D, D) = default;
  // friend auto operator==(D, D) = default;
  // friend auto operator!=(D, D) = default;
  // friend auto operator< (D, D) = default;
  // friend auto operator<=(D, D) = default;
  // friend auto operator> (D, D) = default;
  // friend auto operator>=(D, D) = default;
};

#define assert(X) do { if (!(X)) __builtin_abort(); } while (0)

int main()
{
  D d{42};
  D d2{24};

  assert (is_eq (d <=> d));
  assert (is_lteq (d <=> d));
  assert (is_gteq (d <=> d));
  assert (is_lt (d2 <=> d));
  assert (is_lteq (d2 <=> d));
  assert (is_gt (d <=> d2));
  assert (is_gteq (d <=> d2));

  assert (d == d);
  assert (!(d2 == d));
  assert (!(d == d2));
  assert (d != d2);
  assert (!(d2 != d2));

  assert (d2 < d);
  assert (d2 <= d);
  assert (d > d2);
  assert (d >= d2);
}
