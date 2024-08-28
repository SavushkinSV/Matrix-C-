#include "../s21_matrix.h"

/*
Функция вычитания матриц
*/
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_check_matrix(2, A, B)) {
    return RETURN_ERROR_MATRIX;
  } else if (s21_check_size_matrix(A, B)) {
    return RETURN_ERROR_CALCULATION;
  }

  int status = RETURN_OK;
  status = s21_create_matrix(A->rows, A->columns, result);
  if (!status) {
    for (int i = 0; i < A->rows && status == RETURN_OK; i++) {
      for (int j = 0; j < A->columns && status == RETURN_OK; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        if (!isfinite(result->matrix[i][j])) {
          status = RETURN_ERROR_CALCULATION;
        }
      }
    }
  }

  return status;
}