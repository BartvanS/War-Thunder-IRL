#include <Arduino.h>
#include <calculateStepper.h>

/*
 EXPERIMENT  Only use 1 function for all types of data by localizing the previous data at the origin
 value: e.g. speed
 maxValue: heighest amount the meter supports e.g. max speed = 1000 km/u
 *previousValue: the previous value
 *oldSteps: The previous made steps
*/
float calculateSteps(float value, float maxValue, float *previousValue,  float *oldSteps)
{
      float newSteps = STEPS / (maxValue / value); //Set STEPS to the amount of steps your stepper moter has, mine(28byj-48) has 2048(i think)
      float stepsToMake = newSteps - *oldSteps;
      *previousValue = value;
      *oldSteps = newSteps;
      return stepsToMake;
}