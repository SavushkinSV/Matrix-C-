#include "../s21_matrix.h"
#include "main_test.h"

START_TEST(test_s21_eq_matrix_1) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(1, 3, &A);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_eq_matrix_2) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(6, 3, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_3) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(2, 4, &A);
  s21_create_matrix(6, 3, &B);
  A.columns = 0;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_4) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(1, 7, &A);
  s21_create_matrix(10, 4, &B);
  B.rows = -2;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_5) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(1, 7, &A);
  s21_create_matrix(10, 4, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_6) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 7, &A);
  s21_create_matrix(5, 6, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_7) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(7, 6, &A);
  s21_create_matrix(7, 6, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_8) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);
  s21_init_matrix(&A, 2, 0.123);
  s21_init_matrix(&B, 2, 0.123);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_9) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_init_matrix(&A, 1, 0.000000001);
  s21_init_matrix(&B, 1, 0.000000002);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_10) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(1, 2, &B);
  s21_init_matrix(&A, 1, 0.00000001);
  s21_init_matrix(&B, 1, 0.00000002);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_11) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(1, 2, &B);
  s21_init_matrix(&A, 1, 0.000001);
  s21_init_matrix(&B, 1, 0.0000012);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_12) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(2, 5, &A);
  s21_create_matrix(2, 5, &B);
  s21_init_matrix(&A, 1, 0.003);
  s21_init_matrix(&B, 1, 0.003);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_13) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(4, 7, &A);
  s21_create_matrix(4, 7, &B);
  s21_init_matrix(&A, 15, 17);
  s21_init_matrix(&B, 15, 17);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_14) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_init_matrix(&A, 24, -7.325);
  s21_init_matrix(&B, 24, -7.325);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

TCase *tcase_s21_eq_matrix(void) {
  TCase *tcase = tcase_create("s21_eq_matrix");

  tcase_add_test(tcase, test_s21_eq_matrix_1);
  tcase_add_test(tcase, test_s21_eq_matrix_2);
  tcase_add_test(tcase, test_s21_eq_matrix_3);
  tcase_add_test(tcase, test_s21_eq_matrix_4);
  tcase_add_test(tcase, test_s21_eq_matrix_5);
  tcase_add_test(tcase, test_s21_eq_matrix_6);
  tcase_add_test(tcase, test_s21_eq_matrix_7);
  tcase_add_test(tcase, test_s21_eq_matrix_8);
  tcase_add_test(tcase, test_s21_eq_matrix_9);
  tcase_add_test(tcase, test_s21_eq_matrix_10);
  tcase_add_test(tcase, test_s21_eq_matrix_11);
  tcase_add_test(tcase, test_s21_eq_matrix_12);
  tcase_add_test(tcase, test_s21_eq_matrix_13);
  tcase_add_test(tcase, test_s21_eq_matrix_14);

  return tcase;
}