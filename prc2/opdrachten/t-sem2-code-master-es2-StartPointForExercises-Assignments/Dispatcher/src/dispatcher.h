//
//  dispatcher.h
//
//
//  Created by P Dingemans on 02/07/18.
//
//

#ifndef dispatcher_h
#define dispatcher_h


#include <stdint.h>
#include <stdbool.h>
#include "timer2.h"



//
// dispatcher holds an array dispatcherarray of DISPATCHERELEMENTS with length  NRDISPATCHERELEMENTS
// A DISPATCHERELEMENTS is a struct containing
// - a TIMER struct
// - a bool: indicates id the element is free or not
//

// todo : define your own strcut

// initializes the dispatcher (all elements are freed)
// pre: none
// post: all dispatcher elements are freed and ready to be used
void initdispatcher();

// pre : timerId != null
// post: timerId: id of the timer to be used
// returns :
// 0: succes,
// -1: fail
//   - timerId == null
//   - no more free timers
int8_t alloctimer(uint8_t *timerId);

// pre : timerId != null
// post: dispatcherelement with timerId has status free.
// returns : 0: succes, -1: fail
// - element witht id timerId was not free
int8_t freetimer(uint8_t timerId);

// pre : timer != null
// post : timer points to timerstruct, or nulll;
// returns :
// 0  : succes
// -1 : fail (timerId not valid or found)
int8_t gettimer(uint8_t timerId, TIMER * timer);

#endif
