#include "../s21_matrix.h"
#include "main_test.h"

START_TEST(test_s21_mult_number_1) {
  matrix_t A = {};
  double value = 3.0;
  s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(s21_mult_number(&A, value, NULL), RETURN_ERROR_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_number_2) {
  matrix_t result = {};
  double value = 3.0;
  s21_create_matrix(1, 1, &result);
  ck_assert_int_eq(s21_mult_number(NULL, value, &result), RETURN_ERROR_MATRIX);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_3) {
  matrix_t A = {};
  matrix_t result = {};
  double value = NAN;
  s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(s21_mult_number(&A, value, &result),
                   RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_number_4) {
  matrix_t A = {};
  matrix_t result = {};
  double value = INFINITY;
  s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(s21_mult_number(&A, value, &result),
                   RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_number_5) {
  matrix_t A = {};
  matrix_t result = {};
  double value = 3;
  s21_create_matrix(5, 6, &A);
  s21_init_matrix(&A, 0, 2);
  A.matrix[3][4] = INFINITY;
  ck_assert_int_eq(s21_mult_number(&A, value, &result),
                   RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_6) {
  matrix_t A = {};
  matrix_t result = {};
  double value = 3;
  s21_create_matrix(7, 4, &A);
  s21_init_matrix(&A, 0, 0);
  A.matrix[3][4] = NAN;
  ck_assert_int_eq(s21_mult_number(&A, value, &result),
                   RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_7) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t expected = {};
  double value = -3.14;
  s21_create_matrix(7, 4, &A);
  s21_create_matrix(7, 4, &expected);
  ck_assert_int_eq(s21_mult_number(&A, value, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_mult_number_8) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t expected = {};
  double value = -0.25487;
  s21_create_matrix(7, 4, &A);
  s21_create_matrix(7, 4, &expected);
  s21_init_matrix(&A, 1, 0);
  s21_init_matrix(&expected, -0.25487, 0);
  ck_assert_int_eq(s21_mult_number(&A, value, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_mult_number_9) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t expected = {};
  double value = 2;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 2, A.matrix[2][1] = 3, A.matrix[2][2] = 4;
  expected.matrix[0][0] = 2, expected.matrix[0][1] = 4,
  expected.matrix[0][2] = 6;
  expected.matrix[1][0] = 0, expected.matrix[1][1] = 8,
  expected.matrix[1][2] = 4;
  expected.matrix[2][0] = 4, expected.matrix[2][1] = 6,
  expected.matrix[2][2] = 8;
  ck_assert_int_eq(s21_mult_number(&A, value, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

TCase *tcase_s21_mult_number(void) {
  TCase *tcase = tcase_create("s21_mult_number");

  tcase_add_test(tcase, test_s21_mult_number_1);
  tcase_add_test(tcase, test_s21_mult_number_2);
  tcase_add_test(tcase, test_s21_mult_number_3);
  tcase_add_test(tcase, test_s21_mult_number_4);
  tcase_add_test(tcase, test_s21_mult_number_5);
  tcase_add_test(tcase, test_s21_mult_number_6);
  tcase_add_test(tcase, test_s21_mult_number_7);
  tcase_add_test(tcase, test_s21_mult_number_8);
  tcase_add_test(tcase, test_s21_mult_number_9);

  return tcase;
}