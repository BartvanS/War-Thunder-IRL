//
//  dispatcher.c
//
//
//  Created by P Dingemans on 02/07/18.
//
//

#include "dispatcher2.h"

//
// dispatcher holds an array dispatcherarray of DISPATCHERELEMENTS with length of NRDISPATCHERELEMENTS
// A DISPATCHERELEMENTS is a struct containing
// - a TIMER struct
// - a bool: indicates id the element is free or not
// - a void functionpointer : this is a functionpointer, which is to be called when the time has elapsed.
// - a unsigned long repetitiontime : this time indicates the time between consecutive calls of the functionpointer.
//
// the dispatcher calls the functionpointer every x msec. the number of msecs are defined by the time value




// initializes the dispatcher (all elements are freed)
// pre: none
// post: all dispatcher elements are freed and ready to be used
void initdispatcher()
{

}
// pre : dispacther is initialized
// post :
// for each slot that is not free and the timer is elapsed:
// the funtion has been called
// the timer is restarted again with the repetition time
//
void dodispatch()
{

}

// pre : disptacher initialized
// post: slotId: id of the slot (to be used to free the slot)
// returns :
// 0: succes,
// -1: fail
//   - slotId == null, or functionptr == NULL;
//   - no more free slots
int8_t allocdispatchslot(uint32_t time, void (*functionpointer)(), uint8_t* slotId)
{
	return -1;
}

// pre : timerId != null
// post: dispatcherelement with timerId has status free.
// returns : 0: succes, -1: fail
// - element witht id slotId was  free
int8_t freedispatchslot(uint8_t slotId)
{
		return -1;
}
