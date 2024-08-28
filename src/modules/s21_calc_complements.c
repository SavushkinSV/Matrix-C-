#include "../s21_matrix.h"

/*
Функция получения матрицы алгебраических дополнений
*/
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (s21_check_matrix(1, A) || result == NULL) {
    return RETURN_ERROR_MATRIX;
  } else if ((A->rows != A->columns || A->rows == 1)) {
    return RETURN_ERROR_CALCULATION;
  }

  int status = 0;
  status = s21_create_matrix(A->rows, A->columns, result);
  if (!status) {
    for (int i = 0; i < A->rows && status == RETURN_OK; i++) {
      int sign = i % 2 == 0 ? 1 : -1;
      for (int j = 0; j < A->columns && status == RETURN_OK; j++) {
        matrix_t minor = {};
        if (s21_minor(i, j, A, &minor)) {
          status = RETURN_ERROR_MATRIX;
        } else {
          double minor_determinant = 0;
          status = s21_determinant(&minor, &minor_determinant);
          if (!isfinite(minor_determinant)) {
            status = RETURN_ERROR_CALCULATION;
          }
          if (!status) {
            result->matrix[i][j] = sign * minor_determinant;
            sign = -sign;
          }
          s21_remove_matrix(&minor);
        }
      }
    }
  }

  return status;
}