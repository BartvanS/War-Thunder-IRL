#include <stdio.h>
#include <string.h>

#include "terminal_io.h"

static const char* SpeciesNames[] = {"Cat", "Dog", "Guinea pig", "Parrot"};
static const char* SexNames[] = {"Male", "Female"};
static const char* MenuStrings[] =
{
    "Show Screens",
    "Add Screen",
    "Remove Screen",
    "Find Screen",
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

Date getDate(const char* message)
{
    Date temp = {0, 0, 0};
    printf("%s", message);
    temp.day = getInt("  enter day: ");
    temp.month = getInt("  enter month: ");
    temp.year = getInt("  enter year: ");
    return temp;
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

void printScreens(const Screen* Screens, int nrScreens)
{
    if (Screens != NULL)
    {
        if (nrScreens <= 0)
        {
            printf("\nScreen array is empty, or nrScreens is less than 0\n\n");
        }
        else
        {
            for (int i = 0; i < nrScreens; i++)
            {
                printf("\nScreen %d:\n", i+1);
                printf("Id:     %d\n", Screens[i].Id);
                /*printf("Species:  %s\n", SpeciesNames[Screens[i].Species]);
                printf("Sex:      %s\n", SexNames[Screens[i].Sex]);
                printf("Age:      %d\n", Screens[i].Age); */
                printf("Screen was found:\n");
                //printf("  at date:     %02d-%02d-%02d\n", Screens[i].DateFound.Day, Screens[i].DateFound.Month, Screens[i].DateFound.Year);
            }
        }
    }
}
