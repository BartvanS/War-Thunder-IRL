ASSIGNMENT=dispatcher
DISPATCHER_TEST=dispatcher_test
TIMER_TEST=timer_test

UNITY_FOLDER=../../Unity
RESOURCE_CHECK_FOLDER=../../ResourceDetector
INC_DIRS=-I$(RESOURCE_CHECK_FOLDER) -Isrc
TEST_INC_DIRS=$(INC_DIRS) -I$(UNITY_FOLDER)

SHARED_FILES= src/dispatcher.c\
			  src/timer.c

DISPATCHER_FILES=$(SHARED_FILES) \
	        src/dispatcher_main.cpp\


DISPATCHER_TEST_FILES= $(RESOURCE_CHECK_FOLDER)/resource_detector.c \
             $(RESOURCE_CHECK_FOLDER)/list.c \
	        $(UNITY_FOLDER)/unity.c \
	        $(SHARED_FILES) \
	       	test/dispatcher_test.c

TIMER_TEST_FILES= $(RESOURCE_CHECK_FOLDER)/resource_detector.c \
             $(RESOURCE_CHECK_FOLDER)/list.c \
	        $(UNITY_FOLDER)/unity.c \
	               $(SHARED_FILES) \
	       	test/timer_test.c

HEADER_FILES=src/*.h

CC=gcc

#SYMBOLS=-g  -O0 -std=c99 -Wall -Werror -pedantic
SYMBOLS=-g  -O0 -std=c99
TEST_SYMBOLS=$(SYMBOLS) -DTEST

.PHONY: clean test all

$(ASSIGNMENT): Makefile $(DISPATCHER_FILES)  $(HEADER_FILES)
	$(CC) $(INC_DIRS) $(SYMBOLS) $(DISPATCHER_FILES) -o $(ASSIGNMENT)

$(DISPATCHER_TEST): Makefile $(HEADER_FILES) $(DISPATCHER_TEST_FILES)
	$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(DISPATCHER_TEST_FILES) -o $(DISPATCHER_TEST)

$(TIMER_TEST): Makefile $(HEADER_FILES) $(TIMER_TEST_FILES)
	$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(TIMER_TEST_FILES) -o $(TIMER_TEST)

clean:
	@rm -f $(ASSIGNMENT) $(DISPATCHER_TEST) $(TIMER_TEST)


timertest:  $(TIMER_TEST)
	  @./$(TIMER_TEST)

dispatchertest: $(DISPATCHER_TEST)
	  @./$(DISPATCHER_TEST)

all :  timertest dispatchertest $(ASSIGNMENT)
