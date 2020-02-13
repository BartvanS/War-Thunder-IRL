#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


#include <Arduino.h>

#define TYPE_BYTE (1)
#define TYPE_INT  (2)

void printVariableInfo(String variableName, int value, int* address, byte sizeInBytes);

void printVariableInfo(String variableName, int value, byte* address, byte sizeInBytes);
/* This methid displays a menu, and reads the serial line to retrieve the selection.
 *   The selected menu item is returned.
 */
int readMenuSelection();

/*  The requested address is read from the serial line.
 *  The byte value at this address is shown.
 *  The requested address is returned.
 */
int* handleReadAddressValue(byte dataType);


/*  The requested address and new byte value is read from the serial line.
 *   The byte value at this address is updated with the requested value.
 */
void handleWriteAddressValue(byte dataType) ;

/* This methods read the serial line and tries to convert the characters to an integer return value. */
int readNumberFromSerial() ;

#endif
