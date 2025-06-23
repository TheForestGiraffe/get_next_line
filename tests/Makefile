BUFFER_SIZE ?= 10000

test: test_1.c ../get_next_line.c ../get_next_line_utils.c
	cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=${BUFFER_SIZE} $^
	clear 
	./a.out
