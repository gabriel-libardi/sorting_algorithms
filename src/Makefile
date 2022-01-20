all: memory_test

utils.o: utils.c
		gcc -g -W -Wextra -c utils.c -o utils.o

sorting_algorithms.o: sorting_algorithms.c
		gcc -g -W -Wextra -c sorting_algorithms.c -o sorting_algorithms.o

memory_test.o: memory_test.c
		gcc -g -W -Wextra -c memory_test.c -o memory_test.o

memory_test: utils.o sorting_algorithms.o memory_test.o
		gcc -o memory_test utils.o sorting_algorithms.o memory_test.o