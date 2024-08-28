#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_check_matrix(2, A, B)) {
    return RETURN_ERROR_MATRIX;
  } else if (A->columns != B->rows) {
    return RETURN_ERROR_CALCULATION;
  }

  int status = RETURN_OK;
  status = s21_create_matrix(A->rows, B->columns, result);
  if (!status) {
    for (int m = 0; m < A->rows && status == RETURN_OK; m++) {
      for (int n = 0; n < B->columns && status == RETURN_OK; n++) {
        result->matrix[m][n] = s21_mult_matrix_element(m, n, A, B);
        if (!isfinite(result->matrix[m][n])) {
          status = RETURN_ERROR_CALCULATION;
        }
      }
    }
  }

  return status;
}