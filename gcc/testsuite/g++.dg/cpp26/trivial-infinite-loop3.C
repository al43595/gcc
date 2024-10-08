// P2809R3 - Trivial infinite loops are not Undefined Behavior
// { dg-do compile { target c++11 } }
// { dg-additional-options "-fdump-tree-gimple -fno-inline -Wtautological-compare" }
// { dg-final { scan-tree-dump-not ".ANNOTATE \\\(\[^\n\r]*, 5, 0\\\)" "gimple" } }

volatile int v;
int y;

constexpr bool
foo ()
{
  return true;
}

struct S
{
  constexpr S () : s (true) {}
  constexpr operator bool () const { return s; }
  bool s;
};

#if __cplusplus >= 202002L
namespace std {
  constexpr inline bool
  is_constant_evaluated () noexcept
  {
#if __cpp_if_consteval >= 202106L
    if consteval { return true; } else { return false; }
#else
    return __builtin_is_constant_evaluated ();
#endif
  }
}

constexpr bool
baz ()
{
  return std::is_constant_evaluated ();
}
#endif

void
bar (int x)
{
  switch (x)
    {
    case 0:
      while (foo ()) ++y;
      break;
    case 1:
      while (foo ()) { ++y; }
      break;
    case 2:
      do ++y; while (foo ());
      break;
    case 3:
      do { ++y; } while (foo ());
      break;
    case 4:
      for (v = 42; foo (); ) ++y;
      break;
    case 5:
      for (v = 42; foo (); ) { ++y; }
      break;
    case 6:
      for (int w = 42; foo (); ) ++y;
      break;
    case 7:
      for (int w = 42; foo (); ) { ++y; }
      break;
    case 10:
      while (S {}) ++y;
      break;
    case 11:
      while (S {}) { ++y; }
      break;
    case 12:
      do ++y; while (S {});
      break;
    case 13:
      do { ++y; } while (S {});
      break;
    case 14:
      for (v = 42; S {}; ) ++y;
      break;
    case 15:
      for (v = 42; S {}; ) { ++y; }
      break;
    case 16:
      for (int w = 42; S {}; ) ++y;
      break;
    case 17:
      for (int w = 42; S {}; ) { ++y; }
      break;
#if __cplusplus >= 202002L
    case 20:
      while (baz ()) ++y;
      break;
    case 21:
      while (baz ()) { ++y; }
      break;
    case 22:
      do ++y; while (baz ());
      break;
    case 23:
      do { ++y; } while (baz ());
      break;
    case 24:
      for (v = 42; baz (); ) ++y;
      break;
    case 25:
      for (v = 42; baz (); ) { ++y; }
      break;
    case 26:
      for (int w = 42; baz (); ) ++y;
      break;
    case 27:
      for (int w = 42; baz (); ) { ++y; }
      break;
    case 30:
      while (std::is_constant_evaluated ()) ++y;			// { dg-warning "'std::is_constant_evaluated' always evaluates to false in a non-'constexpr' function" "" { target c++20 } }
      break;
    case 31:
      while (std::is_constant_evaluated ()) { ++y; }			// { dg-warning "'std::is_constant_evaluated' always evaluates to false in a non-'constexpr' function" "" { target c++20 } }
      break;
    case 32:
      do ++y; while (std::is_constant_evaluated ());			// { dg-warning "'std::is_constant_evaluated' always evaluates to false in a non-'constexpr' function" "" { target c++20 } }
      break;
    case 33:
      do { ++y; } while (std::is_constant_evaluated ());		// { dg-warning "'std::is_constant_evaluated' always evaluates to false in a non-'constexpr' function" "" { target c++20 } }
      break;
    case 34:
      for (v = 42; std::is_constant_evaluated (); ) ++y;		// { dg-warning "'std::is_constant_evaluated' always evaluates to false in a non-'constexpr' function" "" { target c++20 } }
      break;
    case 35:
      for (v = 42; std::is_constant_evaluated (); ) { ++y; }		// { dg-warning "'std::is_constant_evaluated' always evaluates to false in a non-'constexpr' function" "" { target c++20 } }
      break;
    case 36:
      for (int w = 42; std::is_constant_evaluated (); ) ++y;		// { dg-warning "'std::is_constant_evaluated' always evaluates to false in a non-'constexpr' function" "" { target c++20 } }
      break;
    case 37:
      for (int w = 42; std::is_constant_evaluated (); ) { ++y; }	// { dg-warning "'std::is_constant_evaluated' always evaluates to false in a non-'constexpr' function" "" { target c++20 } }
      break;
#endif
    default:
      break;
    }
}
