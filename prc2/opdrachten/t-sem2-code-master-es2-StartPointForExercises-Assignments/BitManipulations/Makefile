ASSIGNMENT=bit_stuff

UNITY_FOLDER=../../Unity
TEST_INC_DIRS=-I$(UNITY_FOLDER)

SRC_FILES=$(ASSIGNMENT).c \
          $(ASSIGNMENT)_main.c

TEST_FILES=$(UNITY_FOLDER)/unity.c \
           $(ASSIGNMENT).c \
           $(ASSIGNMENT)_test.c

HEADER_FILES=*.h

TEST = $(ASSIGNMENT)_test

CC=gcc

SYMBOLS=-Wall -Werror -g -Og -std=c99
TEST_SYMBOLS=$(SYMBOLS) -DTEST

.PHONY: all clean test

all: $(ASSIGNMENT) $(TEST)

$(ASSIGNMENT): $(SRC_FILES) $(HEADER_FILES) Makefile
	$(CC) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) -o $(ASSIGNMENT)

$(TEST): Makefile $(TEST_FILES)  $(HEADER_FILES)
	$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(TEST_FILES) -o $(TEST)

clean:
	rm -f $(ASSIGNMENT) $(TEST)

test: $(TEST)
	@./$(TEST)
