#include "../s21_matrix.h"
#include "main_test.h"

START_TEST(test_s21_transpose_1) {
  matrix_t A = {};
  s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(s21_transpose(&A, NULL), RETURN_ERROR_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_transpose_2) {
  matrix_t result = {};
  s21_create_matrix(3, 2, &result);
  ck_assert_int_eq(s21_transpose(NULL, &result), RETURN_ERROR_MATRIX);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_3) {
  matrix_t A = {};
  matrix_t result = {};
  ck_assert_int_eq(s21_transpose(&A, &result), RETURN_ERROR_MATRIX);
}
END_TEST

START_TEST(test_s21_transpose_4) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t expected = {};
  int rows = 2;
  int colums = 3;
  s21_create_matrix(rows, colums, &A);
  s21_init_matrix(&A, 0, 1.5);
  s21_create_matrix(colums, rows, &expected);
  expected.matrix[0][0] = 0, expected.matrix[0][1] = 4.5;
  expected.matrix[1][0] = 1.5, expected.matrix[1][1] = 6;
  expected.matrix[2][0] = 3, expected.matrix[2][1] = 7.5;
  ck_assert_int_eq(s21_transpose(&A, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  ck_assert_int_eq(result.rows, colums);
  ck_assert_int_eq(result.columns, rows);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_transpose_5) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t expected = {};
  int rows = 3;
  int colums = 2;
  s21_create_matrix(rows, colums, &A);
  s21_init_matrix(&A, 1, 1);
  s21_create_matrix(colums, rows, &expected);
  expected.matrix[0][0] = 1, expected.matrix[0][1] = 3,
  expected.matrix[0][2] = 5;
  expected.matrix[1][0] = 2, expected.matrix[1][1] = 4,
  expected.matrix[1][2] = 6;
  ck_assert_int_eq(s21_transpose(&A, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  ck_assert_int_eq(result.rows, colums);
  ck_assert_int_eq(result.columns, rows);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

TCase *tcase_s21_transpose(void) {
  TCase *tcase = tcase_create("s21_transpose");

  tcase_add_test(tcase, test_s21_transpose_1);
  tcase_add_test(tcase, test_s21_transpose_2);
  tcase_add_test(tcase, test_s21_transpose_3);
  tcase_add_test(tcase, test_s21_transpose_4);
  tcase_add_test(tcase, test_s21_transpose_5);

  return tcase;
}