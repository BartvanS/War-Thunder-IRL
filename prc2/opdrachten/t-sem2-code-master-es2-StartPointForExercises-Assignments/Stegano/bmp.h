/*
 * bmp.h
 *
 *  Created on: Feb 23, 2012
 *      Author: student
 */

#ifndef BMP_H_
#define BMP_H_

#include <stdint.h>

// datatypes obtained from http://en.wikipedia.org/wiki/BMP_file_format

typedef struct
{
	uint8_t		magic[2];
} __attribute__ (( packed )) BMP_MAGIC_t;

typedef struct
{
	uint32_t 	filesz;
	uint16_t	creator1;
	uint16_t	creator2;
	uint32_t	bmp_offset;
} __attribute__ (( packed )) BMP_FILE_t;

typedef struct
{
	uint32_t 	header_sz;
	int32_t 	width;
	int32_t 	height;
	uint16_t 	nplanes;
	uint16_t 	bitspp;
	uint32_t 	compress_type;
	uint32_t 	bmp_bytesz;
	int32_t 	hres;
	int32_t 	vres;
	uint32_t 	ncolors;
	uint32_t 	nimpcolors;
} __attribute__ (( packed )) BMP_INFO_t;

#endif /* BMP_H_ */
