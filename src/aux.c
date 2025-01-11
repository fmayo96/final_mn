#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct State {
  int rows, cols;
  double complex** elem;
} State;

void create_state(State* s, int rows, int cols) {
  s->rows = rows;
  s->cols = cols;
  s->elem = (double complex**)calloc(rows, sizeof(double complex));
  for (int i = 0; i < rows; i++) {
    s->elem[i] = (double complex*)calloc(cols, sizeof(double complex));
  }
}

void free_state(State* s) {
  for (int i = 0; i < s->rows; i++) {
    free(s->elem[i]);
  }
  free(s->elem);
}

int main() {
  State s;
  create_state(&s, 3, 3);
  for (int i = 0; i < s.rows; i++) {
    for (int j = 0; j < s.cols; j++) {
      printf("%.2lf ", creal(s.elem[i][j]));
    }
    printf("\n");
  }
  free_state(&s);
}