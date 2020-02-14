#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "screen.h"

/* pre    : ScreenArrayLength must be greater than numberOfScreensPresent
 * post   : ScreenArray is updated with the information from ScreenPtr, the updated number of Screens is passed in newNumberOfScreensPresent
 * returns: 0 on success or -1 if an error occurs
 */
int addScreen(const Screen* ScreenPtr, Screen* ScreenArray, unsigned int ScreenArrayLength, \
              unsigned int numberOfScreensPresent, unsigned int* newNumberOfScreensPresent);

/* pre    :
 * post   : All Screens with id 'ScreenId' are removed from ScreenArray, the updated number of Screens is passed in newNumberOfScreensPresent
 * returns: The number of removed Screens, 0 if no Screens removed or -1 if an error occurs
 */
int removeScreen(int ScreenId, Screen* ScreenArray, unsigned int numberOfScreensPresent, unsigned int* newNumberOfScreensPresent);

/* pre    :
 * post   : The first Screen from ScreenArray with id 'ScreenId' is copied into ScreenPtr
 * returns: 1 on success, 0 if not found or -1 if an error occurs
 */
int findScreenById(int ScreenId, const Screen* ScreenArray, unsigned int numberOfScreensPresent, Screen* ScreenPtr);



#endif
