ASSIGNMENT=encrypt

UNITY_FOLDER=../../Unity
TEST_INC_DIRS=-I$(UNITY_FOLDER)

TEST_FILES=$(UNITY_FOLDER)/unity.c \
           $(ASSIGNMENT)_test.c \
           $(ASSIGNMENT).c \
					 decrypt_test.c \
					 decrypt.c \
					 main.c

HEADER_FILES=*.h

TEST = $(ASSIGNMENT)_test

CC=gcc

SYMBOLS=-Wall -Werror -g -Og -std=c99
TEST_SYMBOLS=$(SYMBOLS) -DTEST

.PHONY: clean test

all: test

$(TEST): Makefile $(TEST_FILES)  $(HEADER_FILES)
	$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(TEST_FILES) -o $(TEST)

clean:
	rm -f $(TEST)

test: $(TEST)
	@./$(TEST)
