#include "screen.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// Note: make sure to set 'resource_detector.h' as the last include.
#include "resource_detector.h"


int addScreen(const Screen* ScreenPtr, Screen* ScreenArray, unsigned int ScreenArrayLength, \
              unsigned int numberOfScreensPresent, unsigned int* newNumberOfScreensPresent)
{
	return -1;
}

int removeScreen(int ScreenId, Screen* ScreenArray, unsigned int numberOfScreensPresent,
                unsigned int* newNumberOfScreensPresent)
{
 	return -1;
}

int findScreenById(int ScreenId, const Screen* ScreenArray, unsigned int numberOfScreensPresent,
                    Screen* ScreenPtr)
{
 	return -1;
}
