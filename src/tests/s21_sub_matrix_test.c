#include "../s21_matrix.h"
#include "main_test.h"

START_TEST(test_s21_sub_matrix_1) {
  matrix_t A = {};
  matrix_t B = {};
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), RETURN_ERROR_MATRIX);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_3) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 6, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_4) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(6, 6, &A);
  s21_create_matrix(6, 6, &B);
  A.matrix[3][3] = INFINITY;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_5) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  A.matrix[0][0] = NAN;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_6) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t expected = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &expected);
  s21_init_matrix(&A, 1, 1);
  s21_init_matrix(&B, 1, 1);
  s21_init_matrix(&expected, 0, 0);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_sub_matrix_7) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t expected = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &expected);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_sub_matrix_8) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t expected = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expected);
  s21_init_matrix(&A, 2, 2.752365);
  s21_init_matrix(&B, 2, 1);
  s21_init_matrix(&expected, 0, 1.752365);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

TCase *tcase_s21_sub_matrix(void) {
  TCase *tcase = tcase_create("s21_sub_matrix");

  tcase_add_test(tcase, test_s21_sub_matrix_1);
  tcase_add_test(tcase, test_s21_sub_matrix_2);
  tcase_add_test(tcase, test_s21_sub_matrix_3);
  tcase_add_test(tcase, test_s21_sub_matrix_4);
  tcase_add_test(tcase, test_s21_sub_matrix_5);
  tcase_add_test(tcase, test_s21_sub_matrix_6);
  tcase_add_test(tcase, test_s21_sub_matrix_7);
  tcase_add_test(tcase, test_s21_sub_matrix_8);

  return tcase;
}