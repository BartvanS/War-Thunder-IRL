#ifndef MEMORY_FUN_INCLUDED
#define MEMORY_FUN_INCLUDED

#include <Arduino.h>

byte readMemoryByte(byte* address) ;

/* Update the byte at the requested 'address' with the requested 'newValue'. */
void writeMemoryByte(byte* address, byte newValue);

/* Return the int value at the requested 'address'. */
int readMemoryInt(int* address);

/* Update the int at the requested 'address' with the requested 'newValue'. */
void writeMemoryInt(int* address, int newValue);

#endif
