#include "memory-fun.h"

#include <Arduino.h>

#include "menu.h"

byte byteA = 16;
byte byteB = 32;
int intA = 4096;
int intB = 8192;

#define MENU_SHOW_MEMORY         (1)
#define MENU_READ_BYTE_ADDRESS_VALUE  (2)
#define MENU_WRITE_BYTE_ADDRESS_VALUE (3)
#define MENU_READ_INT_ADDRESS_VALUE  (4)
#define MENU_WRITE_INT_ADDRESS_VALUE (5)



void handleShowSomeVariables() {
  /* TODO: Update the 4 lines below so the addresses of
   *       the (global) variables (byteA, intA etc. are retrieved.
   */
  byte* addressOfByteA = NULL;
  byte* addressOfByteB = NULL;
  int* addressOfIntA = NULL;
  int* addressOfIntB = NULL;

  printVariableInfo("byteA", byteA, addressOfByteA, sizeof(byteA));
  printVariableInfo("byteB", byteB, addressOfByteB, sizeof(byteB));
  printVariableInfo("intA", intA, addressOfIntA, sizeof(intA));
  printVariableInfo("intB", intB, addressOfIntB, sizeof(intB));
  Serial.println("");
}

/* Return the byte value at the requested 'address'. */
byte readMemoryByte(byte* address) {
  byte value = 0; /* TODO: implement */
  return value;
}

/* Update the byte at the requested 'address' with the requested 'newValue'. */
void writeMemoryByte(byte* address, byte newValue) {
  /* TODO: implement */
}

/* Return the int value at the requested 'address'. */
int readMemoryInt(int* address) {
  int value = 0; /* TODO: implement */
  return value;
}

/* Update the int at the requested 'address' with the requested 'newValue'. */
void writeMemoryInt(int* address, int newValue) {
  /* TODO: implement */
}

/*--------------------------------------------------------------*/
void setup() {
  Serial.begin(9600);
  handleShowSomeVariables();
}

void loop() {
  int selection = readMenuSelection();

  if(MENU_SHOW_MEMORY == selection) {
    handleShowSomeVariables();
  }
  else if(MENU_READ_BYTE_ADDRESS_VALUE == selection) {
    handleReadAddressValue(TYPE_BYTE);
  }
  else if(MENU_WRITE_BYTE_ADDRESS_VALUE == selection) {
    handleWriteAddressValue(TYPE_BYTE);
  }
  else if(MENU_READ_INT_ADDRESS_VALUE == selection) {
    handleReadAddressValue(TYPE_INT);
  }
  else if(MENU_WRITE_INT_ADDRESS_VALUE == selection) {
    handleWriteAddressValue(TYPE_INT);
  }
  else {
    Serial.print("Unsupported menu selection: ");Serial.println(selection);
  }
}
