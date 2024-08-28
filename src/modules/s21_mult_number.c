#include "../s21_matrix.h"

/*
Функция умножения матрицы на число
*/
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (s21_check_matrix(1, A)) {
    return RETURN_ERROR_MATRIX;
  } else if (!isfinite(number)) {
    return RETURN_ERROR_CALCULATION;
  }
  int status = RETURN_OK;
  status = s21_create_matrix(A->rows, A->columns, result);
  if (!status) {
    for (int i = 0; i < A->rows && status == RETURN_OK; i++) {
      for (int j = 0; j < A->columns && status == RETURN_OK; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
        if (!isfinite(result->matrix[i][j])) {
          status = RETURN_ERROR_CALCULATION;
        }
      }
    }
  }

  return status;
}