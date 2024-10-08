/* { dg-do compile } */
/* { dg-options "-maltivec -mno-vsx" } */
/* { dg-require-effective-target powerpc_altivec } */

/* This test was added for an internal compiler error.  The number and
   content of error messages is irrelevant.  */

struct SubData  // { dg-error "" }
{
    inline const Float Clamp(Float f, Float f0, Float f1) // { dg-error "" }
    }
    inline const void SinCos(Float angle, Float& sine, Float& cosine) // { dg-error "" }
    {
        C0 = __builtin_vec_splat(_simdCosEstCoefficients, 0);
        C1 = __builtin_vec_splat(_simdCosEstCoefficients, 1);

