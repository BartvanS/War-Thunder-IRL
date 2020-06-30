#include <Arduino.h>
#include <Stepper.h>
#include "processValues.h"
#include "calculateStepper.h"
Stepper stepper(STEPS, 8, 10, 9, 11);
void setupStepper()
{
  stepper.setSpeed(4);
  setupCalculator();
}

void splitTokens(char *buffer, char *valueType, char *value){
   char splitToken[2] = "@";
    char *token = strtok(buffer, splitToken);
    if (token != NULL)
    {
      strcpy(valueType, token);
      token = strtok(NULL, splitToken);
    }
    if (token != NULL)
    {
      strcpy(value, token);
    }
}
void processValue(char *valueType, char *value)
{
  float stepsToMake;
  if (strcmp(valueType, "speed") == 0)
  {
    float aircraftSpeed = atof(value);
    stepsToMake = calculateStepsSpeedometer(aircraftSpeed);
    stepper.step(-stepsToMake);
    Serial.println("ACK");
  }
  else if (strcmp(valueType, "height") == 0)
  {
  }
  else /* default: */
  {
    Serial.println("NACK"); //Send reply to WPF application Message has not been received correctly
  }
}