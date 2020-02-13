/*
 * stegano.c
 *
 *  Created on: Nov 6, 2011
 *      Author: J. Geurts
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "resource_detector.h"
#include "bmp.h"
#include "stegano.h"

#define    MAX_FILENAME    80

extern uint8_t
SteganoGetSubstring (uint8_t Src, uint8_t SrcPos, uint8_t NrOfBits, uint8_t DestPos)
/* description: get a substring of bits from a uint8_t (i.e. a byte)
 *
 * example: SteganoGetSubstring (Src, 3, 4, 1) with Src=ABCDEFGH (bit H is LSB)
 *          = 000BCDE0
 *
 * parameters:
 *      Src:       byte to get the substring from
 *      SrcPos:    position of the first bit of the substring (LSB=0)
 *      NrOfBits:  length of the substring
 *      DestPos:   position of the first bits of the destination substring
 *
 * return:
 *      substring, starting at DestPos
 */
{
    // to be implemented
    return 0;
}


// should be static in real life, but would give a compiling error in the unchanged code because this function is not yet used
void
ReadHdr (FILE* FilePtr, BMP_MAGIC_t* Magic, BMP_FILE_t* File, BMP_INFO_t* Info)
/*
 * description: read the header of a bmp File, and store the data in the provided parameters
 *
 * parameters:
 *         FilePtr: file, opened for reading
 *         Magic:   output-parameter to store the read BMP_MAGIC_t structure
 *         File:    output-parameter to store the read BMP_FILE_t structure
 *         Info:    output-parameter to store the read BMP_INFO_t structure
 *
 * Note: caller should provide enough memory for parameters 'Magic', 'File' and 'Info'
 */
{
    // to be implemented
}


// should be static in real life, but would give a compiling error in the unchanged code because this function is not yet used
void
WriteHdr (FILE* FilePtr, BMP_MAGIC_t* Magic, BMP_FILE_t* File, BMP_INFO_t* Info)
/*
 * description: write the header of a bmp File, where the data comes from the provided parameters
 *
 * parameters:
 *         FilePtr: file, opened for writing
 *         Magic:   input-parameter with a BMP_MAGIC_t structure
 *         File:    input-parameter with a BMP_FILE_t structure
 *         Info:    input-parameter with a BMP_INFO_t structure
 *
 */
{
    // to be implemented
}


extern void
SteganoMultiplex (const char* File0, const char* File1)
{
    FILE* FilePtr0 = NULL;
    FILE* FilePtr1 = NULL;
    FILE* FilePtr2 = NULL;
    char  buf[MAX_FILENAME];

    for (int NrBits = 0; NrBits <= 8; NrBits++)
    {
        // NrBits: number of bits for the hidden image
        sprintf (buf, "mux_%s_%s_%d.bmp", File0, File1, NrBits);
        FilePtr0 = fopen (File0, "rb");
        FilePtr1 = fopen (File1, "rb");
        FilePtr2 = fopen (buf,   "wb");

        // to be implemented


        fclose (FilePtr0);
        fclose (FilePtr1);
        fclose (FilePtr2);
    }
}


extern void
SteganoMultiplexText (const char* File0, const char* File1)
{
    FILE* FilePtr0 = NULL;
    FILE* FilePtr1 = NULL;
    FILE* FilePtr2 = NULL;
    char  buf[MAX_FILENAME];

    sprintf (buf, "mux_%s_%s.bmp", File0, File1);
    FilePtr0 = fopen (File0, "rb");
    FilePtr1 = fopen (File1, "rb");
    FilePtr2 = fopen (buf,   "wb");

    // to be implemented


    fclose (FilePtr0);
    fclose (FilePtr1);
    fclose (FilePtr2);
}


extern void
SteganoDemultiplex (const char* File0, const char* File1, const char* File2)
{
    FILE* FilePtr0 = NULL;
    FILE* FilePtr1 = NULL;
    FILE* FilePtr2 = NULL;

    FilePtr0 = fopen (File0, "rb");
    FilePtr1 = fopen (File1, "wb");
    FilePtr2 = fopen (File2, "wb");

    // to be implemented


    fclose (FilePtr0);
    fclose (FilePtr1);
    fclose (FilePtr2);
}


extern void
SteganoDemultiplexText (const char* File0, const char* File1, const char* File2)
{
    FILE* FilePtr0 = NULL;
    FILE* FilePtr1 = NULL;
    FILE* FilePtr2 = NULL;

    FilePtr0 = fopen (File0, "rb"); /* binair lezen */
    FilePtr1 = fopen (File1, "wb"); /* binair schrijven */
    FilePtr2 = fopen (File2, "wb"); /* binair schrijven */

    // to be implemented


    fclose (FilePtr0);
    fclose (FilePtr1);
    fclose (FilePtr2);
}

