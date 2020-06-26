#include <Arduino.h>
#include <pinOutPut.h>

//source: https://www.arduino.cc/en/Reference/PortManipulation
//Set the pinmode of 2 to 7 on high or low
void customPinModeLow(uint8_t mask)
{
	uint8_t safeMask = mask & SET_ALL_INPUT_LOW_BYTE; //Always sets port 0 and 1 to value 0 because they are rx and tx
	DDRD = safeMask;
}

//set the pinmode of 8 to 13
void customPinModeHigh(uint8_t mask)
{
	uint8_t safeMask = mask & SET_ALL_INPUT_HIGH_BYTE; //Always sets bit 6 and 7 to value 0 because they are reserved
	DDRB = safeMask;
}

//Set the pinmode of pin 13. true is output, false is input
void setPinMode13(bool onOff)
{
	if (onOff == true)
	{
		DDRB |= MASK_PIN_13_HIGH;
	}
	else
	{
		DDRB &= MASK_PIN_13_LOW;
	}
}