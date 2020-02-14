#ifndef SCREEN_H
#define SCREEN_H

#define MAX_NR_OF_ELEMENTS (10)
#define MAX_LABEL_SIZE (16)
#define MAX_UNIT_SIZE (8)
#define MAX_SCREEN_NAME_SIZE (12)

typedef struct
{
    int hour;
    int min;
    int seconds;
} Time;

typedef struct
{
    int day;
    int month;
    int year;
} Date;

#define MaxNameLength 25
#define MaxLocationLength 100

typedef enum {
  INT_VALUE,
  FLOAT_VALUE,
  STRING_VALUE,
  TIME_VALUE,
  DATA_VALUE
} DataType;

typedef struct {
  int valueInt;
  float valueFloat;
  char valueString[100];
  Date date;
  Time time;
} ElementValue;

typedef struct {
  char label[MAX_LABEL_SIZE];
  char unit[MAX_UNIT_SIZE];
  DataType dataType;
  ElementValue value;
} ScreenElement;

typedef struct
{
    unsigned int Id;
    char name[MAX_SCREEN_NAME_SIZE];
    unsigned int numberOfScreens;
    ScreenElement elements[MAX_NR_OF_ELEMENTS];
} Screen;

#endif
