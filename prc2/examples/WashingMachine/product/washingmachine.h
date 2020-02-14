#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

typedef enum {
  Eco,
  Speed,
  Colorful
} WashingType;

typedef enum {
  Degrees_90,
  Degrees_cold
} Temperature;

typedef struct
{
    unsigned int Id;
    Temperature temperature;
    unsigned int duration;
    WashingType type;
    //TODO rpm, etc.
} WashingProgram;

#endif
