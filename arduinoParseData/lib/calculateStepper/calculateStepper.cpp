#include <Arduino.h>
#include <calculateStepper.h>
float aircraftSpeed = 0;
float previousSpeed = 0;
float oldSteps = 0;

float calculateStepsSpeedometer(float aircraftSpeed){
      int maxSpeed = 1000;
      float newSteps = STEPS / (maxSpeed / aircraftSpeed);
      float stepsToMake = newSteps - oldSteps;
      previousSpeed = aircraftSpeed;
      oldSteps = newSteps;
	return stepsToMake;
}