#include "menu.h"
#include <Arduino.h>

#include "memory-fun.h"

/* Prints information of the given variable over the Serial line. */
void printVariableInfo(String variableName, int value, int* address, byte sizeInBytes) {
  Serial.print(variableName);Serial.print(" = ");
  Serial.print(value);
  Serial.print("\t address: "); Serial.print((int)address);
  Serial.print("\t size: ");Serial.print(sizeInBytes);Serial.println("-byte(s)");
}

void printVariableInfo(String variableName, int value, byte* address, byte sizeInBytes) {
  printVariableInfo(variableName,value,(int*)address,sizeInBytes);
}

/* This methid displays a menu, and reads the serial line to retrieve the selection.
 *   The selected menu item is returned.
 */
int readMenuSelection() {
  Serial.println("*** Use at own risk! This may cause damage to your hardware. ***");
  Serial.println("");
  Serial.println("[1] Show memory values");
  Serial.println("[2] Show byte-value at address");
  Serial.println("[3] Change byte-value at address");
  Serial.println("[4] Show int-value at address");
  Serial.println("[5] Change int-value at address");

  Serial.println("Please provide selection:");
  Serial.println("");
  int selection = readNumberFromSerial();

  return selection;
}

/*  The requested address is read from the serial line.
 *  The byte value at this address is shown.
 *  The requested address is returned.
 */
int* handleReadAddressValue(byte dataType) {
  Serial.println("Provide address:");
  int* address = (int*)readNumberFromSerial();

  if (address > 0) {
    Serial.print("Address: ");
    Serial.println((int)address);

    int value = 0;

    if(TYPE_BYTE == dataType) {
        value = readMemoryByte((byte*)address);
    }
    else if(TYPE_INT == dataType) {
        value = readMemoryInt(address);
    }
    else {
      Serial.print("Unknown data type: ");Serial.println(dataType);
    }

    Serial.print("Value:\t");
    Serial.print(value);
    Serial.print(" = '"); Serial.print((char)value); Serial.print("'");
    Serial.print(" = 0b"); Serial.print(value, BIN);
    Serial.println("");
  }
  else {
    Serial.println("Inccorect address (<0)");
  }

  return address;
}

/*  The requested address and new byte value is read from the serial line.
 *   The byte value at this address is updated with the requested value.
 */
void handleWriteAddressValue(byte dataType) {
  int* address = (int*)handleReadAddressValue(dataType);
  if (address > 0) {
    Serial.println("Provide new value: ");
    int value = readNumberFromSerial();
    Serial.println("Updating value to: "); Serial.println(value);

    if(TYPE_BYTE == dataType) {
      writeMemoryByte((byte*)address, value);
    }
    else if(TYPE_INT == dataType) {
      writeMemoryInt(address,value);
    }
    else {
      Serial.print("Unknown data type: ");Serial.println(dataType);
    }
  }
  else {
    Serial.println("Inccorect address (<0)");
  }
}

/* This methods read the serial line and tries to convert the characters to an integer return value. */
int readNumberFromSerial() {
  int repeat = 0;
  while (Serial.available() == 0) {
    Serial.print(".");
    delay(500);
    repeat++;
    if (repeat > 60) {
      Serial.println("");
      repeat = 0;
    }
  }
  Serial.println("");

  char chars[12] = {'\0',};
  int index = 0;
  while (Serial.available() > 0) {
    chars[index] = Serial.read();
    index++;
  }
  chars[index] = '\0';

  int number = atoi(chars);
  return number;
}
