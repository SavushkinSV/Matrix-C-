#include "../s21_matrix.h"

/*
Функция очистки матрицы
*/
void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    if (A->matrix[0] != NULL) {
      free(A->matrix[0]);
    }
    free(A->matrix);
    A->matrix = NULL;
  }
}