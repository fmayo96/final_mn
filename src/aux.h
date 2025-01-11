#pragma once

#include <cmath>
#include <complex>
#include <vector>

typedef std::vector<double> dvec;
const std::complex<double> I(0, 1);
struct cmatrix {
  int rows;
  std::vector<std::vector<std::complex<double>>> elem;
  cmatrix(int r) : rows(r) {
    elem = std::vector<std::vector<std::complex<double>>>(
        rows, std::vector<std::complex<double>>(rows, 0.0));
  }
  std::complex<double> trace() {
    std::complex<double> tr = 0.0;
    for (int i = 0; i < rows; i++) {
      tr += elem[i][i];
    }
    return tr;
  }
};

dvec linspace(double start, double finish, int length);
void gaussian_state_coh(cmatrix& state, double sigma, double d, double L);