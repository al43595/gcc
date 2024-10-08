// { dg-do compile { target c++20 } }

template<typename T>
  concept C = __is_class(T);

template<const C T> struct S1 { };    // { dg-error "cv-qualified" }
template<volatile C T> struct S2 { }; // { dg-error "cv-qualified" }
template<C* T> struct S3 { };         // { dg-error "invalid" }
template<C const* T> struct S3a { };  // { dg-error "invalid" }
template<C* const T> struct S3b { };  // { dg-error "invalid" }
template<C& T> struct S4 { };         // { dg-error "invalid" }
template<C[3] T> struct S4 { };       // { dg-error "invalid|expected" }
template<C(*T)()> struct S5 { };      // { dg-error "invalid" }
