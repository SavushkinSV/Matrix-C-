#include "../s21_matrix.h"
#include "main_test.h"

START_TEST(test_s21_mult_matrix_1) {
  matrix_t A = {};
  matrix_t B = {};
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), RETURN_ERROR_MATRIX);
}
END_TEST

START_TEST(test_s21_mult_matrix_2) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_mult_matrix_3) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(4, 12, &A);
  s21_create_matrix(2, 5, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_mult_matrix_4) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(5, 3, &A);
  s21_create_matrix(3, 5, &B);
  A.matrix[1][5] = INFINITY;
  s21_init_matrix(&B, 1, -0.25);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_5) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(3, 4, &A);
  s21_create_matrix(4, 3, &B);
  s21_init_matrix(&A, -24.5, 3.784);
  B.matrix[0][2] = NAN;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_6) {
  matrix_t A = {};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 4;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5;
  A.matrix[2][0] = 3, A.matrix[2][1] = 6;
  matrix_t B = {};
  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 1, B.matrix[0][1] = -1, B.matrix[0][2] = 1;
  B.matrix[1][0] = 2, B.matrix[1][1] = 3, B.matrix[1][2] = 4;
  matrix_t expected = {};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 9, expected.matrix[0][1] = 11,
  expected.matrix[0][2] = 17;
  expected.matrix[1][0] = 12, expected.matrix[1][1] = 13,
  expected.matrix[1][2] = 22;
  expected.matrix[2][0] = 15, expected.matrix[2][1] = 15,
  expected.matrix[2][2] = 27;
  matrix_t result = {};

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

TCase *tcase_s21_mult_matrix(void) {
  TCase *tcase = tcase_create("s21_mult_matrix");

  tcase_add_test(tcase, test_s21_mult_matrix_1);
  tcase_add_test(tcase, test_s21_mult_matrix_2);
  tcase_add_test(tcase, test_s21_mult_matrix_3);
  tcase_add_test(tcase, test_s21_mult_matrix_4);
  tcase_add_test(tcase, test_s21_mult_matrix_5);
  tcase_add_test(tcase, test_s21_mult_matrix_6);

  return tcase;
}