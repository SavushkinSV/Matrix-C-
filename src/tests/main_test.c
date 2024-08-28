#include "main_test.h"

extern TCase *tcase_s21_create_matrix(void);
extern TCase *tcase_s21_remove_matrix(void);
extern TCase *tcase_s21_eq_matrix(void);
extern TCase *tcase_s21_sum_matrix(void);
extern TCase *tcase_s21_sub_matrix(void);
extern TCase *tcase_s21_mult_number(void);
extern TCase *tcase_s21_mult_matrix(void);
extern TCase *tcase_s21_transpose(void);
extern TCase *tcase_s21_determinant(void);
extern TCase *tcase_s21_calc_complements(void);
extern TCase *tcase_s21_inverse_matrix(void);

int main(void) {
  Suite *suite = s21_matrix_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_VERBOSE);
  srunner_set_fork_status(runner, CK_FORK);
  int failed_counter = 0;
  failed_counter = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed_counter == 0 ? 0 : 1;
}

Suite *s21_matrix_suite(void) {
  Suite *suite = suite_create("s21_matrix");

  suite_add_tcase(suite, tcase_s21_create_matrix());
  suite_add_tcase(suite, tcase_s21_remove_matrix());
  suite_add_tcase(suite, tcase_s21_eq_matrix());
  suite_add_tcase(suite, tcase_s21_sum_matrix());
  suite_add_tcase(suite, tcase_s21_sub_matrix());
  suite_add_tcase(suite, tcase_s21_mult_number());
  suite_add_tcase(suite, tcase_s21_mult_matrix());
  suite_add_tcase(suite, tcase_s21_transpose());
  suite_add_tcase(suite, tcase_s21_determinant());
  suite_add_tcase(suite, tcase_s21_calc_complements());
  suite_add_tcase(suite, tcase_s21_inverse_matrix());

  return suite;
}
