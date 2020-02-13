#ifndef CHANNEL_H
#define CHANNEL_H

#include <stdint.h>


/*!
 * Initialiase the channel module 
 */ 
void channel_init();

/*!
  * Randomly invert one the bits of the input 'value' parameter
  *
  * @param value: A byte 
  *
  * @return: The input 'value' where on of the bits is randomly inverted 	
  */
uint8_t channel_change_one_random_bit(uint8_t value);

#endif
