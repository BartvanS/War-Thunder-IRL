ASSIGNMENT=watch
WATCH_TEST=watch_test

UNITY_FOLDER=../../Unity
RESOURCE_CHECK_FOLDER=../../ResourceDetector
INC_DIRS=-I$(RESOURCE_CHECK_FOLDER) -Iproduct
TEST_INC_DIRS=$(INC_DIRS) -I$(UNITY_FOLDER)

SHARED_FILES=$(RESOURCE_CHECK_FOLDER)/resource_detector.c \
             $(RESOURCE_CHECK_FOLDER)/list.c \

WATCH_FILES=$(SHARED_FILES) \
	        product/main.c \
					product/watch.c \
					product/watch_i2c.c \
					product/watch_device_simulator.c \
					product/watch_registers.c

WATCH_TEST_FILES=$(SHARED_FILES) \
	        $(UNITY_FOLDER)/unity.c \
	       	test/watch_registers_test.c \
	        product/watch_registers.c

HEADER_FILES=product/*.h

CC=gcc

#SYMBOLS=-g  -O0 -std=c99 -Wall -Werror -pedantic
SYMBOLS=-g  -O0 -std=c99
TEST_SYMBOLS=$(SYMBOLS) -DTEST

.PHONY: clean test watch

all: $(ASSIGNMENT)

$(ASSIGNMENT): Makefile $(WATCH_FILES)  $(HEADER_FILES)
	$(CC) $(INC_DIRS) $(SYMBOLS) $(WATCH_FILES) -o $(ASSIGNMENT)

$(WATCH_TEST): Makefile $(WATCH_TEST_FILES)  $(HEADER_FILES)
	$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(WATCH_TEST_FILES) -o $(WATCH_TEST)

clean:
	@rm -f $(ASSIGNMENT) $(WATCH_TEST)


test: $(WATCH_TEST)
	  @./$(WATCH_TEST)
