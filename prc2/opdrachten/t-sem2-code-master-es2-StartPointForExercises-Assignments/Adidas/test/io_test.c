#include <stdlib.h>
#include <unistd.h>		// for close()

#include "unity.h"

#include "resource_detector.h"
#include "io.h"

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

void test_io(void)
{
    // TODO
}


int main (int argc, char * argv[])
{
	if (argc > 1)
	{
		fprintf (stderr, "ERROR: '%s': invalid arguments\n", argv[0]);
	}
    UnityBegin();

    MY_RUN_TEST(test_io);
    // TODO: your other tests...

    return UnityEnd();
}
