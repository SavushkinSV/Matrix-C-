#ifndef _S21_MATRIX_H
#define _S21_MATRIX_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum s21_return {
  RETURN_OK = 0,
  RETURN_ERROR_MATRIX = 1,
  RETURN_ERROR_CALCULATION = 2
} s21_return;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Вспомогательные функции
int s21_check_matrix(int count, matrix_t *A, ...);
int s21_check_size_matrix(matrix_t *A, matrix_t *B);
void s21_init_matrix(matrix_t *A, double start_value, double step);
double s21_mult_matrix_element(int m, int n, matrix_t *A, matrix_t *B);
int s21_minor(int index_row, int index_colum, matrix_t *A, matrix_t *result);

#endif  // _S21_MATRIX_H
