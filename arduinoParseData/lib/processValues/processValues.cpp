#include <Arduino.h>
#include <Stepper.h>
#include "processValues.h"
#include "calculateStepper.h"
Stepper stepper(STEPS, 8, 10, 9, 11);
void setupStepper()
{
  stepper.setSpeed(4);
}

void splitTokens(char *buffer, char *valueType, char *value)
{
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
//Speed values
float previousSpeed = 0;
float oldSpeedSteps = 0;
//Height values
float previousHeight = 0;
float oldHeightSteps = 0;
void processValue(char *valueType, char *value)
{
  float stepsToMake;
  float floatValue = atof(value);
  if (strcmp(valueType, "speed") == 0)
  {
    stepsToMake = calculateSteps(floatValue, 1000, &previousSpeed, &oldSpeedSteps);
    stepper.step(-stepsToMake);
    Serial.println("ACK");
  }
  else if (strcmp(valueType, "height") == 0)
  {
    stepsToMake = calculateSteps(floatValue, 10000, &previousHeight, &oldHeightSteps);
    stepper.step(-stepsToMake);
    Serial.println("ACK");
  }
  else /* default: */
  {
    Serial.println("NACK"); //Send reply to WPF application Message has not been received correctly
  }
}