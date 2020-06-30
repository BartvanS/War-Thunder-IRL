#ifndef CALCULATE_STEPPER
#define CALCULATE_STEPPER
// #define STEPS 2038
#define STEPS 2048
#define MAX_AMOUNT_METERS 50

float calculateStepsSpeedometer(float aircraftSpeed);
float calculateStepsHeight(float flyingHeight);
void setupCalculator();
float calculateSteps(float value, int index);
#endif