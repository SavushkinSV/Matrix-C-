#include "../s21_matrix.h"

/*
Функция получения обратной матрицы
*/
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (s21_check_matrix(1, A) || result == NULL) {
    return RETURN_ERROR_MATRIX;
  } else if ((A->rows != A->columns)) {
    return RETURN_ERROR_CALCULATION;
  }

  int status = RETURN_OK;
  double determinant = 0;
  status = s21_determinant(A, &determinant);
  if (!status && determinant != 0) {
    if (A->rows == 1) {
      status = s21_create_matrix(1, 1, result);
      if (!status) {
        result->matrix[0][0] = 1 / A->matrix[0][0];
      }
    } else {
      matrix_t components = {};
      matrix_t components_transpose = {};
      status = s21_calc_complements(A, &components);
      if (!status) {
        status = s21_transpose(&components, &components_transpose);
      }
      if (!status) {
        status =
            s21_mult_number(&components_transpose, 1 / determinant, result);
      }
      s21_remove_matrix(&components);
      s21_remove_matrix(&components_transpose);
    }
  } else {
    status = RETURN_ERROR_CALCULATION;
  }

  return status;
}