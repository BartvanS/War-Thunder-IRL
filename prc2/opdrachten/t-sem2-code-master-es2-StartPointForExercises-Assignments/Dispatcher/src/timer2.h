//
//  timer.h
//
//
//  Created by P Dingemans on 02/07/18.
//
//
#ifndef timer2_h
#define timer2_h

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//
// this piece of code decides if we are on an ARDUINO_AVR_UNO
// else it will include arduinostub.h
// this will make a millis() method available on a LINUX system, so tests can be run
//
#ifndef ARDUINO_AVR_UNO
uint32_t millis(void);
#endif

// proceed normally from here
// you need to define your own TIMER timerstruc
//
// TIMER is a struct with two elements:
// timer and timeout.
typedef struct TIMER
{
  // you need to fill this thing
  // think carefully about the types you are going to use.
} TIMER;



// pre : TIMER != NULL
// post: TIMER struct :
//  time := currentmillis
// returns : 0: succes, -1: fail
int8_t startTimer(TIMER* timer);

// pre : none
// post : none
// returns :
// true if currentmillis >= timer+timout
// false : ALL other cases (also if timer == NULL)
bool timerElapsed(TIMER* timer);


#endif /* timer_h */
