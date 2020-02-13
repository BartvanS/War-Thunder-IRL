
// the following code is an example on how to use the dispatcher
// it contains code for an Arduino UNO and for a Linux target
// It does compile, but the standard project will not do anything
// you need to complete the implementation.


// We need to use extern C here as this dispatcher_main is a CPP file
// it NEEDS to be a CPP file as the arduino environment dictates this
// If we would use a C file then we cannot use the Arduino Serial and other libraries,
// as these are C++ classes.
// If the dispatcher is called/included from/in a C file then this extern "C" is not needed
// but for now it sadly is needed...
//
#undef ARDUINO_AVR_UNO

extern "C" {
#include "dispatcher2.h"
}

// the following environment variable has been set by the platformIO environment
// we can use it to check wether we compile for Arduino ARDUINO_AVR_UNO
// if you have a MEGA (or other), you probably need to adapt the variable
#ifdef ARDUINO_AVR_UNO
#include <arduino.h>
//some variables that are needed and pin definition
uint8_t slot1;
uint8_t slot2;
#define LED 13

//
// a function that is called regurlarly
//
void cb1()
{
		digitalWrite(LED, !digitalRead(LED)); // toggle the LED
}
//
// another function that is called regurlarly
//
void cb2()
{
	Serial.println("in2");
	Serial.println(millis());
}

// without comments (hopefully the code speaks for itself)
void setup()
{
		Serial.begin(115200);
		pinMode(LED,OUTPUT);
		initdispatcher();
		allocdispatchslot(2000,cb1,&slot1);
 		allocdispatchslot(3100,cb2,&slot2);
}
void loop()
{
	dodispatch();
}
// here ends the arduino stuff

#else
//
// from here the Linux stuff
//
#include <stdio.h>
void cb1(void)
{
	printf("in 1 \n");
}

void cb2 (void)
{
	printf("in 2 \n");
}
int main()
{
	printf("started \n");
	initdispatcher();
	uint8_t slot1;
	allocdispatchslot(2000,cb1,&slot1);
	uint8_t slot2;
	allocdispatchslot(3100,cb2,&slot2);

	while (1)
	{
		dodispatch();
	}
	return 0;
}
#endif
