#include "../s21_matrix.h"
#include "main_test.h"

START_TEST(test_s21_remove_matrix_1) {
  matrix_t A = {};
  s21_create_matrix(9, 4, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(test_s21_remove_matrix_2) {
  matrix_t A = {};
  s21_init_matrix(&A, 1, 1);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

TCase *tcase_s21_remove_matrix(void) {
  TCase *tcase = tcase_create("s21_remove_matrix");

  tcase_add_test(tcase, test_s21_remove_matrix_1);
  tcase_add_test(tcase, test_s21_remove_matrix_2);

  return tcase;
}