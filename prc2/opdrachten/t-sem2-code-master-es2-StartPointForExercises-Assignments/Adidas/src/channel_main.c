#include <stdlib.h>
#include <stdbool.h>

#include "io.h"
#include "channel.h"
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
		printf("%s inputfile outpfile\n", argv[0]);
		exit(0);
	}

	printf("%s: %s --> %s\n", argv[0],argv[1],argv[2]);

	char* input_file_name = argv[1];
	char* output_file_name = argv[2];

	bool success = io_open_file_for_reading(input_file_name);
	if(!success) myExit(1);

	success = io_open_file_for_writing(output_file_name);
	if(!success) myExit(1);

	channel_init();

	uint8_t byteRead = 0;
	bool isEven = false;
	uint32_t index = 0;

	while(io_read_byte(&byteRead)) {
		isEven = (index %2) == 0;
		if(isEven) {
			byteRead = channel_change_one_random_bit(byteRead);
		}

		success = io_write_byte(byteRead);
		if(!success) myExit(1);
		index++;
	}

	myExit(0);

	return 0;
}
