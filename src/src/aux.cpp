#include "aux.h"

std::vector<double> linspace(double start, double finish, int length) {
  std::vector<double> x(length, 0.0);
  for (int i = 0; i < length; i++) {
    x[i] = (finish - start) * (double)i / (length - 1) + start;
  }
  return x;
}
