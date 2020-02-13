#include <stdlib.h>
#include <unistd.h>		// for close()

#include "unity.h"

#include "resource_detector.h"
#include "decode.h"
#include "encode.h"
#include "parity.h"
#include <stdio.h>

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

extern void setUp(void)
{
    // This is run before EACH test
}

extern void tearDown(void)
{
    // This is run after EACH test
}

void test_decode(void)
{
	
}


int main (int argc, char * argv[])
{
	if (argc > 1)
	{
		fprintf (stderr, "ERROR: '%s': invalid arguments\n", argv[0]);
	}
    UnityBegin();

    MY_RUN_TEST(test_decode);
   
    return UnityEnd();
}
