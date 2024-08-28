#include "../s21_matrix.h"
#include "main_test.h"

START_TEST(test_s21_create_matrix_1) {
  ck_assert_int_eq(s21_create_matrix(1, 7, NULL), RETURN_ERROR_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix_2) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(0, 4, &A), RETURN_ERROR_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix_3) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(3, 0, &A), RETURN_ERROR_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix_4) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(-1, 1, &A), RETURN_ERROR_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix_5) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(1, -1, &A), RETURN_ERROR_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix_6) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), RETURN_OK);
  s21_remove_matrix(&A);
}
END_TEST

TCase *tcase_s21_create_matrix(void) {
  TCase *tcase = tcase_create("s21_create_matrix");

  tcase_add_test(tcase, test_s21_create_matrix_1);
  tcase_add_test(tcase, test_s21_create_matrix_2);
  tcase_add_test(tcase, test_s21_create_matrix_3);
  tcase_add_test(tcase, test_s21_create_matrix_4);
  tcase_add_test(tcase, test_s21_create_matrix_5);
  tcase_add_test(tcase, test_s21_create_matrix_6);

  return tcase;
}
