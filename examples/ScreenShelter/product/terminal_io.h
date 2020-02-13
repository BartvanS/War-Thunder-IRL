#ifndef TERMINAL_IO_H
#define TERMINAL_IO_H

#include "screen.h"

#define MAX_STRLEN 80

typedef enum
{
    MO_ShowScreens,
    MO_AddScreen,
    MO_RemoveScreen,
    MO_FindScreen,
    MO_Quit
} MenuOptions;


int getInt(const char* message);
int getLimitedInt(const char* message, const char* items[], int nrItems);
/* SPECIES getSpecies(void);
SEX getSex(void); */
MenuOptions getMenuChoice(void);
Date getDate(const char* message);
void getStr(const char* message, char* str, int maxLength);
void printScreens(const Screen* Screens, int nrScreens);

#endif
