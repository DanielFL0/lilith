#include "common.h"
#include "matrix.h"

int main(void) {
  srand(time(NULL));
  matrix_t matrix;
  init_matrix(&matrix, 4, 4);
  fill_matrix_zeroes(&matrix);
  print_matrix(&matrix);
  fill_matrix_rand(&matrix, 1.0, 4.0);
  print_matrix(&matrix);
  return 0;
}