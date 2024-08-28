#include "../s21_matrix.h"

/*
Функция вычисляет определитель мартицы
*/
int s21_determinant(matrix_t *A, double *result) {
  if (s21_check_matrix(1, A) || result == NULL) {
    return RETURN_ERROR_MATRIX;
  } else if (A->rows != A->columns) {
    return RETURN_ERROR_CALCULATION;
  }

  int status = 0;
  *result = 0;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else {
    int sign = 1;
    for (int i = 0; i < A->columns && status == RETURN_OK; i++) {
      matrix_t minor = {};
      if (s21_minor(0, i, A, &minor)) {
        status = RETURN_ERROR_MATRIX;
      } else {
        double minor_determinant = 0;
        status = s21_determinant(&minor, &minor_determinant);
        if (!status) {
          *result += sign * A->matrix[0][i] * minor_determinant;
          sign = -sign;
        }
      }
      s21_remove_matrix(&minor);
    }
  }
  if (!isfinite(*result)) {
    status = RETURN_ERROR_CALCULATION;
  }

  return status;
}
