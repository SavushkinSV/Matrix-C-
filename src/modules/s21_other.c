#include "../s21_matrix.h"

/*
Функция проверяет является ли матрица корректной
*/
int s21_check_matrix(int count, matrix_t *A, ...) {
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1)
    return RETURN_ERROR_MATRIX;

  int status = RETURN_OK;
  va_list matrix_list;
  va_start(matrix_list, A);

  for (int i = 0; i < count - 1 && status == RETURN_OK; i++) {
    matrix_t *current_matrix = va_arg(matrix_list, matrix_t *);
    if (current_matrix == NULL || current_matrix->matrix == NULL ||
        current_matrix->rows < 1 || current_matrix->columns < 1) {
      status = RETURN_ERROR_MATRIX;
    }
  }
  va_end(matrix_list);

  return status;
}

/*
Функция проверяет одинаковые ли размеры у матрицы
*/
int s21_check_size_matrix(matrix_t *A, matrix_t *B) {
  int status = RETURN_OK;
  if (A->columns != B->columns || A->rows != B->rows) {
    status = RETURN_ERROR_MATRIX;
  }

  return status;
}

/*
Функция инициализирует матрицу значениями
*/
void s21_init_matrix(matrix_t *A, double start_value, double step) {
  if (s21_check_matrix(1, A)) {
    return;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = start_value;
      start_value += step;
    }
  }
}

/*
Функция вычисляет результат элемента при перемножении матриц
*/
double s21_mult_matrix_element(int m, int n, matrix_t *A, matrix_t *B) {
  double result = 0;
  for (int k = 0; k < B->rows; k++) {
    result += A->matrix[m][k] * B->matrix[k][n];
  }

  return result;
}

/*
Функция получения минора матрицы по заданному элементу
При успешном выполнении возвращает RETURN_OK
*/
int s21_minor(int index_row, int index_colum, matrix_t *A, matrix_t *result) {
  if (s21_check_matrix(1, A) || result == NULL) {
    return RETURN_ERROR_MATRIX;
  } else if (A->rows != A->columns) {
    return RETURN_ERROR_CALCULATION;
  }

  int status = RETURN_OK;
  status = s21_create_matrix(A->rows - 1, A->columns - 1, result);
  if (!status) {
    for (int i = 0, minor_row = 0; i < A->rows; i++) {
      if (i != index_row) {
        for (int j = 0, minor_column = 0; j < A->columns; j++) {
          if (j != index_colum) {
            result->matrix[minor_row][minor_column] = A->matrix[i][j];
            minor_column++;
          }
        }
        minor_row++;
      }
    }
  }

  return status;
}