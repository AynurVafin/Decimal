STD_FLAGS = -Wall -Wextra -Werror -std=c11
COMPILER = gcc
SOURCES_0 = *.o
SOURCES_1 = comparison/*.c helping_tools/*.c math_operations/*.c other_functions/*.c processing_tools/*.c
SOURCES_3 = s21_decimal.a


all: s21_decimal.a  

s21_decimal.a:
	$(COMPILER) -c $(SOURCES_1)
	ar rcs $(SOURCES_3) $(SOURCES_0)


clean:
	@rm -rf *.gcno *.gcda *.o *.out  *.a 

