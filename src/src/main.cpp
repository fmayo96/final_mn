#include <complex>
#include <iostream>
#include <vector>

#include "aux.h"
#include "matrix.h"

const std::complex<double> I(0, 1);

typedef std::complex<double> dcomplex;

int main() {
  Matrix<int> M(3, 3);
  M(0, 1) = 1;
  M(1, 0) = 2;
  M(2, 2) = 3;
  M.Print();
  return 0;
}
