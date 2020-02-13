/*
 * stegano.h
 *
 *  Created on: Nov 6, 2011
 *      Author: J. Geurts
 */

#ifndef STEGANO_H_
#define STEGANO_H_

#include <stdint.h>

extern uint8_t SteganoGetSubstring (uint8_t src, uint8_t src_pos, uint8_t nrof_bits, uint8_t dest_pos);

extern void SteganoMultiplex (const char* File0, const char* File1);
extern void SteganoMultiplexText (const char* File0, const char* File1);
extern void SteganoDemultiplex (const char* File0, const char* File1, const char* File2);
extern void SteganoDemultiplexText (const char* File0, const char* File1, const char* File2);

#endif /* STEGANO_H_ */
