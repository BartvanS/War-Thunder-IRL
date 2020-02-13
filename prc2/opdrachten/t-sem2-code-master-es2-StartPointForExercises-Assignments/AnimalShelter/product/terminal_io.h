#ifndef TERMINAL_IO_H
#define TERMINAL_IO_H

#include "animal.h"

#define MAX_STRLEN 80

typedef enum
{
    MO_ShowAnimals,
    MO_AddAnimal,
    MO_RemoveAnimal,
    MO_SortAnimalsByAge,
    MO_SortAnimalsByYearFound,
    MO_SortAnimalsBySex,
    MO_FindAnimal,
    MO_Load,
    MO_Save,
    MO_Quit
} MenuOptions;


int getInt(const char* message);
int getLimitedInt(const char* message, const char* items[], int nrItems);
SPECIES getSpecies(void);
SEX getSex(void);
MenuOptions getMenuChoice(void);
DATE getDate(const char* message);
void getStr(const char* message, char* str, int maxLength);
void printAnimals(const ANIMAL* animals, int nrAnimals);

#endif
