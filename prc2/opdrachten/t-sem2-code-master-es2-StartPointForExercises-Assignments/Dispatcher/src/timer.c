//
//  timer.c
//
//
//  Created by P Dingemans on 02/07/18.
//
//
//
// this piece of code decides if we are on an ARDUINO_AVR_UNO
// else it will create one for LINUX
// this will make a millis() method available on a LINUX system, so tests can be done (if you want)
// so please do not remove this...
#include "timer2.h"

#ifdef ARDUINO_AVR_UNO
#include <arduino.h>
#else
//
// lets define our own millis if we are not on Arduino platform
//
#include <stdio.h>
#include <sys/time.h>
uint32_t millis(void)
{
	uint32_t ms; // Milliseconds
	struct timeval tv;
	gettimeofday(&tv, NULL);
	ms= tv.tv_usec / 1000 +tv.tv_sec*1000;
	return ms;
}
#endif


//
// from here you can implement your own timer stuff
//


//
// TIMER is a struct with two elements:
// timer and timeout.
//
// pre : TIMER != NULL
// post: TIMER struct :
// time := currentmillis
// returns : 0: succes, -1: fail
int8_t startTimer(TIMER* timer)
{
	return -1;
}

// pre : none
// post : none
// returns :
// true if currentmillis >= timer
// false : ALL other cases (also if timer == NULL)
bool timerElapsed(TIMER* timer)
{
	return false;
}
