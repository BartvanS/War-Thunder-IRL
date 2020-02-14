#define REDPIN    (7)
#define GREENPIN  (8)
#define BUTTONPIN (10)

#include <Arduino.h>

void user_begin()
{
  pinMode(BUTTONPIN, INPUT);
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
}

boolean user_button_isPressed()
{
  /* Poor implementation, don't use this as a reference... */
  if (digitalRead(BUTTONPIN) == HIGH)
  {
    while (digitalRead(BUTTONPIN) != LOW) {
      Serial.println("Waiting for button release...");
    }
    return true;
  }

  return false;
}

void user_turnAlarmSignalsOn()
{
  digitalWrite(REDPIN, HIGH);
}

void user_turnAlarmSignalsOff()
{
  digitalWrite(REDPIN, LOW);
}

void user_showAlarmOn()
{
  Serial.println("ON");
  digitalWrite(GREENPIN, HIGH);
}

void user_showAlarmOff()
{
  Serial.println("OFF");
  digitalWrite(GREENPIN, LOW);
}

