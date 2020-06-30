#include <Arduino.h>
#include <calculateStepper.h>
/*
 EXPERIMENT: Only use 1 function for all types of data
 value: e.g. speed
 maxValue: heighest amount the meter supports
 index: place in arrays
 */
float previousValue[MAX_AMOUNT_METERS];
float oldSteps[MAX_AMOUNT_METERS];
//Call this once in setup before calling calculateSteps
void setupCalculator()
{
      for (int i = 0; i < MAX_AMOUNT_METERS; ++i)
      {
            previousValue[i] = 0;
            oldSteps[i] = 0;
      }
}
float calculateSteps(float value, float maxValue, int index)
{
      float newSteps = STEPS / (maxValue / value);
      float stepsToMake = newSteps - oldSteps[index];
      previousValue[index] = value;
      oldSteps[index] = newSteps;
      return stepsToMake;
}


//Possible outdated, needs testing
float previousSpeed = 0;
float oldSpeedSteps = 0;
float calculateStepsSpeedometer(float aircraftSpeed)
{
      float maxSpeed = 1000;
      float newSteps = STEPS / (maxSpeed / aircraftSpeed);
      float stepsToMake = newSteps - oldSpeedSteps;
      previousSpeed = aircraftSpeed;
      oldSpeedSteps = newSteps;
      return stepsToMake;
}

float previousHeight = 0;
float oldHeightSteps = 0;
float calculateStepsHeight(float flyingHeight)
{
      float maxHeight = 10000;
      float newSteps = STEPS / (maxHeight / flyingHeight);
      float stepsToMake = newSteps - oldHeightSteps;
      previousHeight = flyingHeight;
      oldHeightSteps = newSteps;
      return stepsToMake;
}

