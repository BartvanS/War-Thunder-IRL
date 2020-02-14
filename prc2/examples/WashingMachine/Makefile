ASSIGNMENT=main
ADMIN_TEST=main_test

UNITY_FOLDER=../../Unity
RESOURCE_CHECK_FOLDER=../../ResourceDetector
INC_DIRS=-I$(RESOURCE_CHECK_FOLDER) -Iproduct
TEST_INC_DIRS=$(INC_DIRS) -I$(UNITY_FOLDER)

SHARED_FILES=$(RESOURCE_CHECK_FOLDER)/resource_detector.c \
             $(RESOURCE_CHECK_FOLDER)/list.c \

ASSIGNMENT_FILES=$(SHARED_FILES) \
	             product/$(ASSIGNMENT).c \
	             product/terminal_io.c \
			     		 product/administration.c \

ADMIN_FILES=$(SHARED_FILES) \
	        $(UNITY_FOLDER)/unity.c \
	        test/administration_test.c \
	        product/administration.c

HEADER_FILES=product/*.h

CC=gcc

#SYMBOLS=-g  -O0 -std=c99 -Wall -Werror -pedantic
SYMBOLS=-g  -O0 -std=c99
TEST_SYMBOLS=$(SYMBOLS) -DTEST

.PHONY: clean test file admin

all: $(ASSIGNMENT)

$(ASSIGNMENT): Makefile $(ASSIGNMENT_FILES)  $(HEADER_FILES)
	$(CC) $(INC_DIRS) $(SYMBOLS) $(ASSIGNMENT_FILES) -o $(ASSIGNMENT)

$(ADMIN_TEST): Makefile $(ADMIN_FILES)  $(HEADER_FILES)
	$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(ADMIN_FILES) -o $(ADMIN_TEST)

clean:
	@rm -f $(ASSIGNMENT) $(FILE_ELEMENT_TEST) $(ADMIN_TEST)

file_test: $(FILE_ELEMENT_TEST)
	@./$(FILE_ELEMENT_TEST)

test: $(ADMIN_TEST)
	@./$(ADMIN_TEST)
