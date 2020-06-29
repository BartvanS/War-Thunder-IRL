#include <Arduino.h>
#include "readSerial.h"
#include "processValues.h"

float MovingAverage = 0;
void setup()
{
  Serial.begin(9600);
  setupStepper();
}
//todo: support multiple values being sent with a upgraded protol to make the values distinct
void loop()
{
  char buffer[buffer_length];
  int messageAvailable = readSerial(buffer);
  if (messageAvailable == 1)
  {
    char valueType[20];
    char value[20];
    splitTokens(buffer, valueType, value);
    processValue(valueType, value);
    // lcd.clear();
    // lcd.print("%s\n", value);
  }
}