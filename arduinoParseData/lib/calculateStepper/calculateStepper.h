#ifndef CALCULATE_STEPPER
#define CALCULATE_STEPPER
#define STEPS 2048
#define MAX_AMOUNT_METERS 50

float calculateSteps(float value, float maxValue, float *previousValue,  float *oldSteps);

#endif