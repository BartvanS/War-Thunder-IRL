#ifndef PINOUTPUT
#define PINOUTPUT
/*
	This code is meant to shift the gpio registers of the arduino. Use this instead of digitalwrite
	pins 0 and 1 are reserved for rx and tx
*/
#include <stdint.h>
#define SET_ALL_INPUT_LOW_BYTE 0b11111100 // sets pins 2 to 7 on input. 0 and 1 is rx and tx
#define SET_ALL_INPUT_HIGH_BYTE 0b00111111 // sets pin 8 to 13. bit 6 and 7 are reserved
#define SET_ALL_OUTPUT 0b00000000
#define MASK_PIN_13_HIGH 0b00100000
#define MASK_PIN_13_LOW 0b00011111
void customPinModeLow(uint8_t mask);

void customPinModeHigh(uint8_t mask);

void setPinMode13(bool onOff);
#endif