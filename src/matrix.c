#include "common.h"
#include "matrix.h"

double rand_float(void) {
    return (double) rand() / (double) RAND_MAX;
}

double sigmoid_double(double x) {
  return (1 / 1 + pow(EULER_NUMBER, -x))
}

void init_matrix(matrix_t* matrix, uint64_t rows, uint64_t columns) {
  matrix->rows = rows;
  matrix->columns = columns;
  matrix->buffer = malloc(sizeof(double) * rows * columns);
}

void write_matrix(matrix_t* matrix, uint64_t row, uint64_t column, double data) {
    
}

void fill_matrix_zeroes(matrix_t* matrix) {
  uint64_t total = matrix->rows * matrix->columns;
  for (uint64_t i = 0; i < total; i++)
    matrix->buffer[i] = 0;
}

void fill_matrix_rand(matrix_t* matrix, double lower_bound, double upper_bound) {
  uint64_t total = matrix->rows * matrix->columns;
  for (uint64_t i = 0; i < total; i++)
    matrix->buffer[i] = rand_float() * (upper_bound - lower_bound) + lower_bound;;
}

void print_matrix(matrix_t* matrix) {
  uint64_t total = matrix->rows * matrix->columns;
  uint64_t row = 0;
  uint64_t column = 0;
  for (uint64_t i = 0; i < total; i++)
    printf("%lf\n", matrix->buffer[i]);
}