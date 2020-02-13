#ifndef ANIMAL_H
#define ANIMAL_H

typedef enum
{
    Cat,
    Dog,
    GuineaPig,
    Parrot
} SPECIES;

typedef enum
{
    Male,
    Female
} SEX;

typedef struct
{
    int Day;
    int Month;
    int Year;
} DATE;

#define MaxNameLength 25
#define MaxLocationLength 100

typedef struct
{
    int     Id;
    SPECIES Species;
    SEX     Sex;
    int     Age;
    DATE    DateFound;
} ANIMAL;

#endif
