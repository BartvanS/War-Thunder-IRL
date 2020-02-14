#include <stdio.h>
#include <string.h>

#include "terminal_io.h"

static const char* SpeciesNames[] = {"Cat", "Dog", "Guinea pig", "Parrot"};
static const char* SexNames[] = {"Male", "Female"};
static const char* MenuStrings[] =
{
    "Show WashingPrograms",
    "Add WashingProgram",
    "Remove WashingProgram",
    "Find WashingProgram",
    "Quit"
};

int getInt(const char* message)
{
    char line[MAX_STRLEN];
    char* result = NULL;
    int value = -1;

    printf ("%s", message);
    result = fgets (line, sizeof(line), stdin);
    if (result != NULL)
    {
        sscanf (result, "%d", &value);
    }

    return value;
}

int getLimitedInt(const char* message, const char* items[], int nrItems)
{
    int choice = -1;
    do
    {
        for (int i = 0; i < nrItems; i++)
        {
            printf("  [%d] %s\n", i, items[i]);
        }
        choice = getInt(message);
    } while (choice < 0 || choice >= nrItems);

    return choice;
}

/*
SPECIES getSpecies(void)
{
    return (SPECIES)getLimitedInt("enter species: ", SpeciesNames, 4);
}

SEX getSex(void)
{
    return (SEX)getLimitedInt("enter sex: ", SexNames, 2);
}
*/

MenuOptions getMenuChoice(void)
{
    return (MenuOptions)getLimitedInt("choice: ", MenuStrings, 10);
}


void getStr(const char* message, char* str, int maxLength)
{
    char line[maxLength];
    char* result = NULL;

    printf ("%s", message);
    result = fgets (line, sizeof(line), stdin);
    if (result != NULL)
    {
        if(result[strlen(result)-1]=='\n')
        {
            result[strlen(result)-1] = '\0';
        }
        strncpy(str, result, maxLength);
    }
}

void printWashingPrograms(const WashingProgram* WashingPrograms, int nrWashingPrograms)
{
    if (WashingPrograms != NULL)
    {
        if (nrWashingPrograms <= 0)
        {
            printf("\nWashingProgram array is empty, or nrWashingPrograms is less than 0\n\n");
        }
        else
        {
            for (int i = 0; i < nrWashingPrograms; i++)
            {
                printf("\nWashingProgram %d:\n", i+1);
                printf("Id:     %d\n", WashingPrograms[i].Id);
                /*printf("Species:  %s\n", SpeciesNames[WashingPrograms[i].Species]);
                printf("Sex:      %s\n", SexNames[WashingPrograms[i].Sex]);
                printf("Age:      %d\n", WashingPrograms[i].Age); */
                printf("WashingProgram was found:\n");
                //printf("  at date:     %02d-%02d-%02d\n", WashingPrograms[i].DateFound.Day, WashingPrograms[i].DateFound.Month, WashingPrograms[i].DateFound.Year);
            }
        }
    }
}
