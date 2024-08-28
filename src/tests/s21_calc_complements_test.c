#include "../s21_matrix.h"
#include "main_test.h"

START_TEST(test_s21_calc_complements_1) {
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), RETURN_ERROR_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_2) {
  matrix_t result = {};
  ck_assert_int_eq(s21_calc_complements(NULL, &result), RETURN_ERROR_MATRIX);
}
END_TEST

START_TEST(test_s21_calc_complements_3) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_4) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(1, 1, &A);
  s21_init_matrix(&A, 1, 0);
  ck_assert_int_eq(s21_calc_complements(&A, &result), RETURN_ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_5) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;
  matrix_t result = {};
  matrix_t expected = {};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 0, expected.matrix[0][1] = 10,
  expected.matrix[0][2] = -20;
  expected.matrix[1][0] = 4, expected.matrix[1][1] = -14,
  expected.matrix[1][2] = 8;
  expected.matrix[2][0] = -8, expected.matrix[2][1] = -2,
  expected.matrix[2][2] = 4;
  ck_assert_int_eq(s21_calc_complements(&A, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_calc_complements_6) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2, A.matrix[0][1] = 4, A.matrix[0][2] = 5;
  A.matrix[1][0] = 3, A.matrix[1][1] = -1, A.matrix[1][2] = 8;
  A.matrix[2][0] = -5, A.matrix[2][1] = 1, A.matrix[2][2] = 2;
  matrix_t result = {};
  matrix_t expected = {};
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = -10, expected.matrix[0][1] = -46,
  expected.matrix[0][2] = -2;
  expected.matrix[1][0] = -3, expected.matrix[1][1] = 29,
  expected.matrix[1][2] = -22;
  expected.matrix[2][0] = 37, expected.matrix[2][1] = -1,
  expected.matrix[2][2] = -14;
  ck_assert_int_eq(s21_calc_complements(&A, &result), RETURN_OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

TCase *tcase_s21_calc_complements(void) {
  TCase *tcase = tcase_create("s21_calc_complements");

  tcase_add_test(tcase, test_s21_calc_complements_1);
  tcase_add_test(tcase, test_s21_calc_complements_2);
  tcase_add_test(tcase, test_s21_calc_complements_3);
  tcase_add_test(tcase, test_s21_calc_complements_4);
  tcase_add_test(tcase, test_s21_calc_complements_5);
  tcase_add_test(tcase, test_s21_calc_complements_6);

  return tcase;
}