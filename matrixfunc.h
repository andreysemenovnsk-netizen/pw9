#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stddef.h>

void buffer_clearing(void);
int set_matrix_size(size_t *rows, size_t *cols);
int fill_the_matrix(int *matptr, size_t rows, size_t cols);
void show_matrix(const int *matptr, size_t rows, size_t cols);

void summ_of_elements_colum_matrix(const int *matptr, size_t rows, size_t cols, int *col_sums);
size_t numbers_below_k(const int *matptr, size_t rows, size_t cols, int k);
int summ_cols_range(const int *matptr, size_t rows, size_t cols, size_t k, size_t m);

void read_summ_of_elements_colum_matrix(const int *matptr, size_t rows, size_t cols);
void read_numbers_below_k(const int *matptr, size_t rows, size_t cols);
void read_summ_cols_range(const int *matptr, size_t rows, size_t cols);

#endif