#include "../s21_matrix.h"
#include "main_test.h"

START_TEST(test_s21_inverse_matrix_1) {
  matrix_t A = {};
  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), RETURN_ERROR_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t result = {};
  ck_assert_int_eq(s21_inverse_matrix(NULL, &result), RETURN_ERROR_MATRIX);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(2, 5, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_4) {
  matrix_t A = {};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 0.2;
  matrix_t expected = {};
  s21_create_matrix(1, 1, &expected);
  expected.matrix[0][0] = 5;
  matrix_t result = {};
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_inverse_matrix_5) {
  matrix_t A = {};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 0, A.matrix[1][1] = 1;
  matrix_t expected = {};
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 1, expected.matrix[0][1] = -2;
  expected.matrix[1][0] = 0, expected.matrix[1][1] = 1;
  matrix_t result = {};
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_inverse_matrix_6) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2, A.matrix[0][1] = 5, A.matrix[0][2] = 7;
  A.matrix[1][0] = 6, A.matrix[1][1] = 3, A.matrix[1][2] = 4;
  A.matrix[2][0] = 5, A.matrix[2][1] = -2, A.matrix[2][2] = -3;

  matrix_t expected = {};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 1, expected.matrix[0][1] = -1,
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38, expected.matrix[1][1] = 41,
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27, expected.matrix[2][1] = -29,
  expected.matrix[2][2] = 24;
  matrix_t result = {};
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_inverse_matrix_7) {
  matrix_t A = {};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = INFINITY;
  matrix_t result = {};
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

TCase *tcase_s21_inverse_matrix(void) {
  TCase *tcase = tcase_create("s21_inverse_matrix");

  tcase_add_test(tcase, test_s21_inverse_matrix_1);
  tcase_add_test(tcase, test_s21_inverse_matrix_2);
  tcase_add_test(tcase, test_s21_inverse_matrix_3);
  tcase_add_test(tcase, test_s21_inverse_matrix_4);
  tcase_add_test(tcase, test_s21_inverse_matrix_5);
  tcase_add_test(tcase, test_s21_inverse_matrix_6);
  tcase_add_test(tcase, test_s21_inverse_matrix_7);

  return tcase;
}