#include <Arduino.h>
// #include <LiquidCrystal_I2C.h>
#include <Stepper.h>
#include "calculateStepper.h"
#include "readSerial.h"

// LiquidCrystal_I2C lcd(0x27, 16, 2);
Stepper stepper(STEPS, 8, 10, 9, 11);
float MovingAverage = 0;
void setup()
{
  // lcd.init();
  // lcd.backlight();
  // lcd.print("Starting...");
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
    Serial.println("ACK");
    // Serial.println("NACK"); //if something goes wrong send message to application
    float stepsToMake = calculateStepsSpeedometer(buffer);
    stepper.step(-stepsToMake); //rotate stepper counterclockwise as the stepper is positioned wronly
  }
}