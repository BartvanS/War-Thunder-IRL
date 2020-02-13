/* 
 * auteur : Freddy Hurkmans
 * datum  : November 15th 2015
 * code   : C99
 */

#include <string.h>
#include "buffer.h"

// Note: there is still a bug in this file 
// (even outside findBufferValueAsUint32() and readBufferValueAsUint32()
// Can you find it?

static uint8_t buffer[BUFFER_SIZE];

static int indexOutOfRange(uint32_t index)
{
    return (index < 0) || (index >= BUFFER_SIZE);
}


void initBuffer(void)
{
    memset(buffer, 0, BUFFER_SIZE);
}

int readBufferValueAsUint8(uint32_t index, uint8_t* value)
{
    if (indexOutOfRange(index) || value == NULL)
    {
        return -1;
    }

    *value = buffer[index];
    return 0;
}

int writeBufferValueAsUint8(uint32_t index, uint8_t value)
{
    if (indexOutOfRange(index))
    {
        return -1;
    }

    buffer[index] = value;
    return 0;
}

int readBufferValueAsUint32(uint32_t index, uint32_t* value)
{
    if (indexOutOfRange(index) || value == NULL)
    {
        return -1;
    }

    // next line has a bug (on purpose (such that test cases will fail...))
    uint32_t* p = (uint32_t*)&buffer[0];
    *value = *p;
    return 0;
}

int writeBufferValueAsUint32(uint32_t index, uint32_t value)
{
    if (indexOutOfRange(index))
    {
        return -1;
    }

    uint32_t* p = (uint32_t*)&buffer[index];
    *p = value;
    return 0;
}

uint8_t*	
findBufferValueAsUint8(uint8_t value)
{
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (buffer[i] == value)
		{
			return (&buffer[i]);
		}
	}
	// not found:
	return (NULL);
}

uint32_t*	
findBufferValueAsUint32(uint32_t value)
{
	// not yet implemented (on purpose (such that test cases will fail...))
    return (NULL);
}
