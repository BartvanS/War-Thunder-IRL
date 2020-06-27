#include <Arduino.h>
#include <Stepper.h>
#include "calculateStepper.h"
#include "readSerial.h"

Stepper stepper(STEPS, 8, 10, 9, 11);
float MovingAverage = 0;
void setup()
{
  Serial.begin(9600);
  stepper.setSpeed(4);
}

void loop()
{
  char buffer[buffer_length];
  int messageAvailable = readSerial(buffer);
  if (messageAvailable == 1)
  {
    // lcd.clear();
    // lcd.print(buffer);
    Serial.println("ACK"); //Send reply to WPF application Message has been received
    float stepsToMake = calculateStepsSpeedometer(buffer);
    stepper.step(-stepsToMake);
  }
  //todo: if something goes wrong send message to WPF application
  // else if (messageAvailable == -1)
  // {
  // Serial.println("NACK");
  // }
}