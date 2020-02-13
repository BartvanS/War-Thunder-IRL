/* 
 * auteur : Freddy Hurkmans
 * datum  : November 15th 2015
 * code   : C99
 */

#include <stdint.h>

#ifndef BUFFER_H
#define BUFFER_H

#define BUFFER_SIZE 20

void initBuffer(void);

int readBufferValueAsUint8(uint32_t index, uint8_t* value);
int writeBufferValueAsUint8(uint32_t index, uint8_t value);


int readBufferValueAsUint32(uint32_t index, uint32_t* value);
int writeBufferValueAsUint32(uint32_t index, uint32_t value);
uint8_t* findBufferValueAsUint8(uint8_t value);
uint32_t* findBufferValueAsUint32(uint32_t value);

#endif
