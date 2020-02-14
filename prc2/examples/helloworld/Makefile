NAME=main

FILES= main.c\
       hello.c

HEADER_FILES=*.h

CC=gcc

SYMBOLS=-Wall -Werror -g -pedantic -O0 -std=c99

.PHONY: clean

all: product

product: Makefile $(FILES) $(HEADER_FILES)
	$(CC) $(SYMBOLS) $(FILES) -o $(NAME)

run: product
	./$(NAME)

clean:
	rm -f $(NAME)
