//
//  timer.h
//  
//
//  Created by P Dingemans on 02/07/18.
//
//

#ifndef timer1_h
#define timer1_h


#include <stdint.h>
#include <stdbool.h>


// pre : timer != null
// post: timer := currentmillis + timeout
void startTimer(uint32_t* timer, uint32_t timout);

// pre : none
// post : none
// returns : true if currentmillis >= timer
bool timerElapsed(uint32_t timer);

#endif /* timer_h */
