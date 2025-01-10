#pragma once

#include <vector>

template <typename T>
class Matrix {
 private:
  int rows, cols;
  std::vector<std::vector<T>> elem;

 public:
  Matrix(int rows, int cols) : rows(rows), cols(cols) {
    elem = std::vector<std::vector<T>>(rows, std::vector<T>(cols, 0.0));
  }
  T& operator()(int i, int j) { return elem[i][j]; }
  void Print() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        std::cout << elem[i][j] << " ";
      }
      std::cout << "\n";
    }
  }
};