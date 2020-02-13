#include <stdio.h>
#include <stdlib.h>

#include "decode.h"
#include "io.h"
#include "resource_detector.h"

void myExit(int result) {
	io_close_file_for_reading();
	io_close_file_for_writing();
	exit(result);
}

int main(int argc, char * argv[])
{
	if(argc < 3) {
		printf("Please provide file name arguments:\n");
		printf("%s inputfile outpfile mode\n", argv[0]);
		exit(0);
	}

	printf("%s: %s --> %s\n", argv[0],argv[1],argv[2]);

	char* input_file_name = argv[1];
	char* output_file_name = argv[2];

	bool success = io_open_file_for_reading(input_file_name);
	if(!success) myExit(1);

	success = io_open_file_for_writing(output_file_name);
	if(!success) myExit(1);

	uint8_t high = 0, low = 0;
	uint8_t nibbleHigh = 0, nibbleLow = 0;
	while(true) {
	success = io_read_byte(&high);
		if(!success) break;

		success = io_read_byte(&low);
		if(!success) {
			printf("Expecting another byte in the file!\n");
			printf("Will not decode previous nibble.\n");
			break;
		}

		decode_byte(high, &nibbleHigh);
		decode_byte(low, &nibbleLow);

		char decoded = decode_combine_nibbles(nibbleHigh,nibbleLow);

		success = io_write_byte(decoded);
		if(!success) myExit(1);
	}

	myExit(0);

	return 0;
}
