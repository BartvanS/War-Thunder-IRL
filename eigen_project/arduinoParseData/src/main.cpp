#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

char serialChars;
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.print("Hello, world!");
  Serial.begin(9600);
  servo.attach(3);
  servo.write(0);
}

void readSerial()
{
  if (Serial.available())
  {
    
    if (Serial.available() > 0)
    {
       
      String aircraftSpeedString = Serial.readString();
      // serialChars = Serial.read();
      // lcd.print(aircraftSpeedString);
      float aircraftSpeed = aircraftSpeedString.toInt();
      // servo hoek = snelheid / (hoeveel km p u op de meter) * 180 graden
      float degreesSpeedDouble = aircraftSpeed / 500 * 180 ;
      lcd.clear();
      Serial.println("test");
      lcd.print(degreesSpeedDouble);
      int degreesSpeed = (int)degreesSpeedDouble;
      servo.write(degreesSpeed);
    }
  }
}

void loop()
{
  readSerial();
}

