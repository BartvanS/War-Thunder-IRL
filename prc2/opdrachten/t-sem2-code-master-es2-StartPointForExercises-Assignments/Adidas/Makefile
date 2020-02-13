CC 				= gcc

CFLAGS 			= -Wall -Werror -g -Og -std=c99 $(INC_DIRS)

LDFLAGS 		= -s

SRC_DIR 		= ./src
TEST_DIR 		= ./test
UNITY_DIR 		= ./../../Unity
RESOURCE_DIR 	= ./../../ResourceDetector
INC_DIRS		= -I$(SRC_DIR) -I$(UNITY_DIR) -I$(RESOURCE_DIR)

# the largest file in /boot:
#TESTFILE 		= `ls -S /boot/* | head -1`
TESTFILE 		= Makefile

HEADER_FILES	= $(SRC_DIR)/*.h

SHARED_OBJ_FILES   = $(SRC_DIR)/channel.o \
				  $(SRC_DIR)/encode.o \
				  $(SRC_DIR)/decode.o \
				  $(SRC_DIR)/io.o \
				  $(SRC_DIR)/parity.o \
				  $(RESOURCE_DIR)/resource_detector.o \
				  $(RESOURCE_DIR)/list.o \

TARGETS 		= encode channel decode parity_test encode_test channel_test decode_test io_test

.PHONY:	all clean test

all:	$(TARGETS)

encode:	$(SRC_DIR)/encode_main.o $(SHARED_OBJ_FILES)
		$(CC) $(LDFLAGS) $^ -o $@

channel:	$(SRC_DIR)/channel_main.o $(SHARED_OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

decode:	$(SRC_DIR)/decode_main.o $(SHARED_OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

parity_test: $(SHARED_OBJ_FILES) $(TEST_DIR)/parity_test.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(UNITY_DIR)/unity.c -o $@
		./$@

encode_test: $(SHARED_OBJ_FILES) $(TEST_DIR)/encode_test.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(UNITY_DIR)/unity.c -o $@
		./$@

channel_test: $(SHARED_OBJ_FILES) $(TEST_DIR)/channel_test.c
		$(CC) $(CFLAGS) $(LDFLAGS) $^ $(UNITY_DIR)/unity.c -o $@
		./$@

decode_test: $(SHARED_OBJ_FILES) $(TEST_DIR)/decode_test.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(UNITY_DIR)/unity.c -o $@
		./$@

io_test: $(SHARED_OBJ_FILES) $(TEST_DIR)/io_test.c
		$(CC) $(CFLAGS) $(LDFLAGS) $^ $(UNITY_DIR)/unity.c -o $@
		./$@

.c.o: $(HEADER_FILES)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(TARGETS) $(SRC_DIR)/*.o $(TEST_DIR)/*.o $(RESOURCE_DIR)/*.o *.tmp

test: all
	./parity_test
	./encode_test
	./channel_test
	./decode_test
	@echo "Testing" $(TESTFILE)
	@ls -l $(TESTFILE)
	./encode $(TESTFILE) a.tmp
	./channel a.tmp b.tmp
	./decode  b.tmp c.tmp
	cmp $(TESTFILE) c.tmp
