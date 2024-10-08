extern "C" void abort ();

template<typename T>
struct S
{
  T a, b, c, d;

  T sum (void)
  {
    T val = 0;
    val += a + b + this->c + this->d;
    return val;
  }

  T sum_offload (void)
  {
    T val = 0;
    #pragma omp target map(val)
    val += a + b + this->c + this->d;
    return val;
  }
};

int main (void)
{
  S<int> s = { 1, 2, 3, 4 };
  if (s.sum () != s.sum_offload ())
    abort ();
  return 0;
}
