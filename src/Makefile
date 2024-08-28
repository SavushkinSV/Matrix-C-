CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
LIBFLAGS=-lcheck -lm -lsubunit -lrt -lpthread

MODULES_DIR=modules/
ALL_CFILES=$(wildcard s21_*.c)					\
		   $(wildcard $(MODULES_DIR)s21_*.c)
OBJ_LIBRARY := $(patsubst %.c, %.o, $(ALL_CFILES))

TEST_DIR=tests/
TEST_CFILES=$(wildcard $(TEST_DIR)*_test.c)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: clean s21_matrix.a

s21_matrix.a: $(OBJ_LIBRARY)
	ar rcs $@ $(OBJ_LIBRARY)
	ranlib $@
	rm -f */*.o *.o

test: clean $(TEST_CFILES) s21_matrix.a
	$(CC) $(CFLAGS) $(TEST_CFILES) s21_matrix.a -o test.out $(LIBFLAGS)
	./test.out

gcov_report: CFLAGS += -coverage
gcov_report: clean test
	gcov -f $(ALL_CFILES)
	@mkdir report
	./test.out
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --output-directory ./report	
	open report/index.html

check:
	clang-format -style='{BasedOnStyle: Google}' -n */*.c
	clang-format -style='{BasedOnStyle: Google}' -n *.h */*.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h */*.c */*.h	

clean:
	@echo Deleting temporary files ...
	@rm -f */*.o *.a *.o *.out *.txt
	@rm -f *.gcno *.gcov *.gcda
	@rm -f */*.gcno */*.gcov */*.gcda
	@rm -f *.info
	@rm -fr report

.PHONY: all clean s21_matrix.a test



