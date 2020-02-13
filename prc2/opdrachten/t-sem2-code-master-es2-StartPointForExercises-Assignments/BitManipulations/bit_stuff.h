#pragma once

#include <stdint.h>

/* pre : -
 * post: the number of bits with value 1 is counted and returned
 */
unsigned int count_ones(unsigned int value);

/* pre : -
 * post: a bitmask with a given width and a given shift is generated (so w=5 and s=1 gives 00111110)
 */
void make_bitmask(unsigned int width, unsigned int shift, unsigned int *mask);

/* pre : -
 * post: 'masked_value' is assigned the value of 'value' with the 'mask' applied
 */
void apply_bitmask(unsigned int value, unsigned int mask, unsigned int* masked_value);

/* pre : -
 * post: the bit of index 'bit_index' of 'value' is flipped: 0 --> 1, 1 --> 0.
 */
void flip_bit(unsigned int value, unsigned int bit_index, unsigned int *updated_value);

/* pre : -
 * post: the high and low nibbles of 'value' of stored in 'high_nibble' and 'low_nibble'.
 */
void extract_nibbles_from_byte(uint8_t value, uint8_t *high_nibble, uint8_t* low_nibbe);

/* pre : -
 * post: the nibble values of the 'high_nibble' and 'low_nibble' are combined and stored in 'value'
 */
void combine_nibles_to_byte(uint8_t high_nibble, uint8_t low_nibbe, uint8_t* value);
