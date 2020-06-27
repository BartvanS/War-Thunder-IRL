#include <Arduino.h>
#include <readSerial.h>
typedef enum
{
  WAITING_FOR_MESSAGE,
  READING_MESSAGE
} communicationState;
communicationState comState = WAITING_FOR_MESSAGE;
#define MESSAGE_START ('#')
#define MESSAGE_STOP ('%')
char incomingMessage[buffer_length];
int i = 0;
int readSerial(char *buf)
{
  buf[0] = '\0';  // lets clear the c-string
  int retval = 0; // we start with no errors and nothing to return

  // read the serial port buffer as long there are characters
  while (Serial.available() > 0)
  {
    int incomingByte = Serial.read();
    if (comState == WAITING_FOR_MESSAGE)
    {
      if (incomingByte == MESSAGE_START)
      {
        comState = READING_MESSAGE;
      }
    }
    else if (comState == READING_MESSAGE)
    {
      if (incomingByte == MESSAGE_STOP)
      {
        strcpy(buf, incomingMessage);
        comState = WAITING_FOR_MESSAGE;
        retval = 1;
        memset(incomingMessage, 0, sizeof(incomingMessage));
        i = 0;
      }
      else
      {
        incomingMessage[i] += (char)incomingByte;
        i++;
      }
    }
  } 
  return retval;
}