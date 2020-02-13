#include <stdlib.h>

#include "unity.h"
#include "channel.h"
#include "parity.h"
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

extern void setUp(void)
{
  	channel_init();
}

extern void tearDown(void)
{
    // This is run after EACH test
}

static void test_channel(void)
{
  
}

int main (int argc, char * argv[])
{
	if (argc > 1)
	{
		fprintf (stderr, "ERROR: '%s': invalid arguments\n", argv[0]);
	}
    UnityBegin();

    MY_RUN_TEST(test_channel);

    return UnityEnd();
}
