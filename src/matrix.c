#include "common.h"
#include "matrix.h"

double rand_float(void) {
  return (double) rand() / (double) RAND_MAX;
}

double sigmoid_double(double x) {
  return (1 / 1 + pow(EULER_NUMBER, -x));
}

void init_matrix(matrix_t* matrix, uint64_t rows, uint64_t columns) {
  matrix->rows = rows;
  matrix->columns = columns;
  matrix->offset = columns;
  matrix->buffer = malloc(sizeof(double) * rows * columns);
}

double get_matrix(matrix_t* matrix, uint64_t row, uint64_t column) {
  uint64_t idx = column * matrix->offset + row;
  return matrix->buffer[idx];
}

void write_matrix(matrix_t* matrix, uint64_t row, uint64_t column, double data) {
  uint64_t idx = column * matrix->offset + row;
  matrix->buffer[idx] = data;
}

void fill_matrix_zeroes(matrix_t* matrix) {
  for (uint64_t i = 0; i < matrix->rows; i++) {
    for (uint64_t j = 0; j < matrix->columns; j++) {
      write_matrix(matrix, i, j, 0.0);
    }
  }
}

void fill_matrix_rand(matrix_t* matrix, double lower_bound, double upper_bound) {
  for (uint64_t i = 0; i < matrix->rows; i++) {
    for (uint64_t j = 0; j < matrix->columns; j++) {
      write_matrix(matrix, i, j, rand_float() * (upper_bound - lower_bound) + lower_bound);
    }
  }
}

void print_matrix(matrix_t* matrix) {
  for (uint64_t i = 0; i < matrix->rows; i++) {
    for (uint64_t j = 0; j < matrix->columns; j++) {
      printf("%lf ", get_matrix(matrix, i, j));
    }
    printf("\n");
  }
}