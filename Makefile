CC=gcc
CFLAGS=-Wall -Wextra -Werror -c -std=c11
GCOVFLAGS:=--coverage
SOURCES:= s21_test.c s21_string.c
OBJECTS:=$(SOURCES:.c=.o)
UNAME = $(shell uname -s)
ifeq ($(UNAME),Darwin)
	CHECK=-lcheck -lm -lpthread -fprofile-arcs
endif
ifeq ($(UNAME),Linux)
	CHECK=-lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs
endif

all: test gcov_report

.c.o:
	$(CC) $(CFLAGS) $(GCOVFLAGS) $< -o $@ 

s21_string.a: s21_verter.o
	ar rcs s21_string.a s21_verter.o

s21_verter.o: s21_string.c
	$(CC) $(CFLAGS) s21_string.c -o s21_verter.o

lint:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.h $(SOURCES)
	rm CPPLINT.cfg

test: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(CHECK)
	./$@

gcov_report:
	gcovr -r . --html --html-details -o coverage_report.html
	gcov -f s21_string.gcda

rebuild: clean all

clean:
	rm -rf a.*
	rm -f -r test
	rm -f -r s21_string.a
	rm -f *.o
	rm -f *.gc*
	rm -rf *.css
	rm -rf *.html

.PHONY: all clean rebuild lint check gcovr
