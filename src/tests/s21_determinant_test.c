#include "../s21_matrix.h"
#include "main_test.h"

START_TEST(test_s21_determinant_1) {
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  ck_assert_int_eq(s21_determinant(&A, NULL), RETURN_ERROR_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  double result = 0;
  ck_assert_int_eq(s21_determinant(NULL, &result), RETURN_ERROR_MATRIX);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  matrix_t A = {};
  s21_create_matrix(2, 3, &A);
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_4) {
  matrix_t A = {};
  s21_create_matrix(1, 1, &A);
  s21_init_matrix(&A, -1, 0);
  double result = 0;
  double expected = -1;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_OK);
  ck_assert_double_eq(result, expected);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  matrix_t A = {};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 4, A.matrix[0][1] = 2;
  A.matrix[1][0] = 2, A.matrix[1][1] = 1;
  double result = 0;
  double expected = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_OK);
  ck_assert_double_eq(result, expected);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_6) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  A.matrix[2][0] = 7, A.matrix[2][1] = 8, A.matrix[2][2] = 9;
  double result = 0;
  double expected = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_OK);
  ck_assert_double_eq(result, expected);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_7) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = -2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 0, A.matrix[1][2] = 6;
  A.matrix[2][0] = -7, A.matrix[2][1] = 8, A.matrix[2][2] = 9;
  double result = 0;
  double expected = 204;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_OK);
  ck_assert_double_eq(result, expected);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_8) {
  matrix_t A = {};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 5, A.matrix[0][1] = 1, A.matrix[0][2] = 2,
  A.matrix[0][3] = 7;
  A.matrix[1][0] = 3, A.matrix[1][1] = 0, A.matrix[1][2] = 0,
  A.matrix[1][3] = 2;
  A.matrix[2][0] = 1, A.matrix[2][1] = 3, A.matrix[2][2] = 4,
  A.matrix[2][3] = 5;
  A.matrix[3][0] = 2, A.matrix[3][1] = 0, A.matrix[3][2] = 0,
  A.matrix[3][3] = 3;
  double result = 0;
  double expected = 10;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_OK);
  ck_assert_double_eq(result, expected);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_9) {
  matrix_t A = {};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = INFINITY, A.matrix[0][1] = 2;
  A.matrix[1][0] = 2, A.matrix[1][1] = 1;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
}
END_TEST

TCase *tcase_s21_determinant(void) {
  TCase *tcase = tcase_create("s21_determinant");

  tcase_add_test(tcase, test_s21_determinant_1);
  tcase_add_test(tcase, test_s21_determinant_2);
  tcase_add_test(tcase, test_s21_determinant_3);
  tcase_add_test(tcase, test_s21_determinant_4);
  tcase_add_test(tcase, test_s21_determinant_5);
  tcase_add_test(tcase, test_s21_determinant_6);
  tcase_add_test(tcase, test_s21_determinant_7);
  tcase_add_test(tcase, test_s21_determinant_8);
  tcase_add_test(tcase, test_s21_determinant_9);

  return tcase;
}