#include "../s21_matrix.h"

/*
Функция создания матрицы
Возвращает RETURN_OK при успещном создании
*/
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL) return RETURN_ERROR_MATRIX;

  int status = RETURN_OK;

  if (rows < 1 || columns < 1) {
    status = RETURN_ERROR_MATRIX;
    result->matrix = NULL;
  }
  double **array_pointer = NULL;
  if (!status) {
    result->rows = rows;
    result->columns = columns;
    array_pointer = (double **)calloc(rows, sizeof(double *));
    if (array_pointer == NULL) status = RETURN_ERROR_MATRIX;
  }
  if (!status) {
    double *value_pointer = (double *)calloc(rows * columns, sizeof(double));
    if (value_pointer == NULL) {
      status = RETURN_ERROR_MATRIX;
      free(array_pointer);
    } else {
      for (int i = 0; i < rows; i++)
        array_pointer[i] = value_pointer + columns * i;
      result->matrix = array_pointer;
    }
  }

  return status;
}