#define ALARMPIN  (9)

#include <Arduino.h>

void sensor_begin()
{
  pinMode(ALARMPIN, INPUT);
}

boolean sensor_isTriggered()
{
  return digitalRead(ALARMPIN);
}

