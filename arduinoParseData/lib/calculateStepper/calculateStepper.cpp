#include <Arduino.h>
#include <calculateStepper.h>

/*
 EXPERIMENT  Only use 1 function for all types of data by localizing the previous data at the origin
 value: e.g. speed
 maxValue: heighest amount the meter supports
 *previousValue: the previous value
 *oldSteps: The previous made steps
*/
float calculateSteps(float value, float maxValue, float *previousValue,  float *oldSteps)
{
      float newSteps = STEPS / (maxValue / value);
      float stepsToMake = newSteps - *oldSteps;
      *previousValue = value;
      *oldSteps = newSteps;
      return stepsToMake;
}