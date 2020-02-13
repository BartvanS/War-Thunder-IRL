#ifndef DECODE_H_
#define DECODE_H_

#include <stdint.h>

/*!
	* Combines the nibbles located at the 4-least-significant bits of
  * parameters 'low' and 'high' into one byte.
  *
	* @param high: A nibble that contains the 4 most-significant bits
  * @param low:  A nibble that contains the 4 most-significant bits
  *
  * @return: A byte that combines the high and low nibble.
  */
uint8_t decode_combine_nibbles(uint8_t high, uint8_t low);

/*!
	* Decodes a nibble from a byte that contains the nible (4-bits) and
  * corresponding parity bits (3-bits). See assignment for more details.
  *
  * pre-condition: parameter 'nibble' may not be NULL. This method
  *                will NOT check for NULL parameters.
  *
	* @param in:     A bytes that contains a nibble and parity bits.
  * @param nibble: The address to which the decoded nibble
  *                of 'in' will be written.
  *
  */
void decode_byte(uint8_t in, uint8_t *nibble);

#endif
