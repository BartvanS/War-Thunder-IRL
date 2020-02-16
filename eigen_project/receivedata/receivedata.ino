#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
int incomingByte = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.print("Hello, world!");
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  servo.attach(3);
  servo.write(0);
}

void loop()
{
  if (Serial.available()) {
    lcd.clear();
    digitalWrite(2, HIGH);
    // Write all characters received with the serial port to the LCD.
    if (Serial.available() > 0) {
      String aircraftSpeedString = Serial.readString();
      float aircraftSpeed = aircraftSpeedString.toInt();
      float degreesSpeedDouble = aircraftSpeed / 1000 * 180 ;
      lcd.print(degreesSpeedDouble);
      int degreesSpeed = (int)degreesSpeedDouble;
      servo.write(degreesSpeed);
    }
  }
}
