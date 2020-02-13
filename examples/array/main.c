#include <stdio.h>
#include <stdint.h>

int main (int argc, char * argv[])
{
	uint8_t values[] = {1,4,9,16,25};
	uint8_t numberOfValues = sizeof(values)/sizeof(values[0]);
	uint8_t* valuePtr = values;
	uint8_t* valueStartPtr = values;
	
	for(uint8_t i = 0; i < numberOfValues; i++) {
		printf("Index: %i value: %d, ptr %p\n",i,values[i],(void*)&values[i]);
		printf("         value: %d, ptr %p\n",*valuePtr,(void*)valuePtr);
		printf("         value: %d, ptr %p\n",*(valueStartPtr+i),(void*)(valueStartPtr+i));
		valuePtr++;
	}

	printf("\n");

	uint32_t bigValues[] = { 65000, 128000, 54000, 28, 42};
	uint8_t numberOfBigValues = sizeof(bigValues)/sizeof(bigValues[0]);
	uint32_t* bigValuePtr = bigValues;
	uint32_t* bigValueStartPtr = bigValues;

	for(uint8_t i = 0; i < numberOfBigValues; i++) {
		printf("Index: %i value: %d, ptr %p\n",i,bigValues[i],(void*)&bigValues[i]);
		printf("         value: %d, ptr %p\n",*bigValuePtr,(void*)bigValuePtr);
		printf("         value: %d, ptr %p\n",*(bigValueStartPtr+i),(void*)(bigValueStartPtr+i));
		bigValuePtr++;	
	}

}
