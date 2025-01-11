#include <complex>
#include <fstream>
#include <iostream>
#include <vector>

#include "aux.h"

int main() {
  double sigma = 0.25, d = 1.0, L = 5.0;
  int Nx = 512;
  cmatrix state(Nx);
  gaussian_state_coh(state, sigma, d, L);
  std::ofstream outFile("test.txt");
  for (int i = 0; i < state.rows; i++) {
    for (int j = 0; j < state.rows; j++) {
      outFile << state.elem[i][j].real() << " ";
    }
    outFile << "\n";
  }
  outFile.close();
  return 0;
}
