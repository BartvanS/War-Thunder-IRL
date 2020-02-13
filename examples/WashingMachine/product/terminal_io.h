#ifndef TERMINAL_IO_H
#define TERMINAL_IO_H

#include "washingmachine.h"

#define MAX_STRLEN 80

typedef enum
{
    MO_ShowWashingPrograms,
    MO_AddWashingProgram,
    MO_RemoveWashingProgram,
    MO_FindWashingProgram,
    MO_Quit
} MenuOptions;


int getInt(const char* message);
int getLimitedInt(const char* message, const char* items[], int nrItems);
/* SPECIES getSpecies(void);
SEX getSex(void); */
MenuOptions getMenuChoice(void);
void getStr(const char* message, char* str, int maxLength);
void printWashingPrograms(const WashingProgram* WashingPrograms, int nrWashingPrograms);

#endif
