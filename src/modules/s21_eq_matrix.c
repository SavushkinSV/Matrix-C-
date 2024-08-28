#include "../s21_matrix.h"

/*
Функция сравнения матриц
Сравнение проводится до седьмого знака после запятой включительно
*/
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (s21_check_matrix(2, A, B) || s21_check_size_matrix(A, B)) {
    return FAILURE;
  }
  int status = SUCCESS;
  for (int i = 0; i < A->rows && status == SUCCESS; i++) {
    for (int j = 0; j < A->columns && status == SUCCESS; j++) {
      double tmp = (fabs(A->matrix[i][j] - B->matrix[i][j]));
      if (tmp >= 1e-7) status = FAILURE;
    }
  }

  return status;
}