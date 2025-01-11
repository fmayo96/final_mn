#include "aux.h"

std::vector<double> linspace(double start, double finish, int length) {
  std::vector<double> x(length, 0.0);
  for (int i = 0; i < length; i++) {
    x[i] = (finish - start) * (double)i / (length - 1) + start;
  }
  return x;
}

void gaussian_state_coh(cmatrix& state, double sigma, double d, double L) {
  dvec x = linspace(-L / 2.0, L / 2.0, state.rows);
  dvec y = linspace(-L / 2.0, L / 2.0, state.rows);
  double dx = x[1] - x[0];
  for (int i = 0; i < state.rows; i++) {
    for (int j = 0; j < state.rows; j++) {
      state.elem[i][j] = (exp(-pow(x[i] - d / 2.0, 2) / (2 * sigma * sigma)) +
                          exp(-pow(x[i] + d / 2.0, 2) / (2 * sigma * sigma))) *
                         (exp(-pow(y[j] - d / 2.0, 2) / (2 * sigma * sigma)) +
                          exp(-pow(y[j] + d / 2.0, 2) / (2 * sigma * sigma)));
    }
  }
  double tr = state.trace().real();
  for (int i = 0; i < state.rows; i++) {
    for (int j = 0; j < state.rows; j++) {
      state.elem[i][j] /= (tr * dx);
    }
  }
}