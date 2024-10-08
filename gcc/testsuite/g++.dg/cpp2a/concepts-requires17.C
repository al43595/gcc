// { dg-do compile { target c++20 } }

template<typename T>
concept Type = true;

template<typename T>
concept C =
  requires (T a) {
    { a.f() } -> Type; // OK
    { a.g() } -> const Type*; // { dg-error "not a plain type-constraint" }
  };
