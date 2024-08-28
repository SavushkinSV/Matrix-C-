#include "../s21_matrix.h"

/*
Функция транспонирования матрицы
*/
int s21_transpose(matrix_t *A, matrix_t *result) {
  if (s21_check_matrix(1, A) || result == NULL) return RETURN_ERROR_MATRIX;

  int status = RETURN_OK;
  status = s21_create_matrix(A->columns, A->rows, result);
  if (!status) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }

  return status;
}