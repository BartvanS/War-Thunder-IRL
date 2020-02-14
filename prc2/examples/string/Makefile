NAME=main

FILES= main.c

CC=gcc

SYMBOLS=-Wall -Werror -g -pedantic -O0 -std=c99

.PHONY: clean

all: product

product: Makefile $(FILES)
	$(CC) $(SYMBOLS) $(FILES) -o $(NAME)

run: product
	./$(NAME)

clean:
	rm -f $(NAME)
