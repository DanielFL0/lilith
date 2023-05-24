#ifndef MATRIX_H
#define MATRIX_H

#define EULER_NUMBER 2.71828

double rand_double(void);
double sigmoid_double(double x);

typedef struct matrix_t {
  uint64_t  rows;
  uint64_t  columns;
  double*   buffer;
} matrix_t;

void init_matrix(matrix_t* matrix, uint64_t rows, uint64_t columns);
double get_matrix(matrix_t* matrix, uint64_t row, uint64_t column);
void write_matrix(matrix_t* matrix, uint64_t row, uint64_t column, double data);
void fill_matrix_zeroes(matrix_t*);
void fill_matrix_rand(matrix_t* matrix, double lower_bound, double upper_bound);
void dot_matrix(matrix_t* matrix_a, matrix_t* matrix_b, matrix_t* matrix_c);
void sum_matrix(matrix_t* matrix_a, matrix_t* matrix_b);
void print_matrix(matrix_t* matrix);

#endif