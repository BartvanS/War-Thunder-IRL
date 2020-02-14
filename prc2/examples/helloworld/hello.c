#include "hello.h"
#include <stdio.h> // Needed for method 'printf'

void hello_please(uint8_t repeat) {
	for(uint8_t i = 0; i < repeat; i++)
	{
		printf("[%d] - Hello world!\n", i);
	}
}
