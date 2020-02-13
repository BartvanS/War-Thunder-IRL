ASSIGNMENT=animal_shelter
FILE_ELEMENT_TEST=file_element_test
ADMIN_TEST=admin_test

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
	             product/file_element.c

FILE_ELEMENT_FILES=$(SHARED_FILES) \
		           $(UNITY_FOLDER)/unity.c \
		           test/file_element_test.c \
		           product/file_element.c

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

$(FILE_ELEMENT_TEST): Makefile $(FILE_ELEMENT_FILES)  $(HEADER_FILES)
	$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(FILE_ELEMENT_FILES) -o $(FILE_ELEMENT_TEST)

$(ADMIN_TEST): Makefile $(ADMIN_FILES)  $(HEADER_FILES)
	$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(ADMIN_FILES) -o $(ADMIN_TEST)

clean:
	@rm -f $(ASSIGNMENT) $(FILE_ELEMENT_TEST) $(ADMIN_TEST)

file_test: $(FILE_ELEMENT_TEST)
	@./$(FILE_ELEMENT_TEST)

test: $(ADMIN_TEST)
	@./$(ADMIN_TEST)
