#include <stdio.h>
#include <string.h>

#include "terminal_io.h"

static const char* SpeciesNames[] = {"Cat", "Dog", "Guinea pig", "Parrot"};
static const char* SexNames[] = {"Male", "Female"};
static const char* MenuStrings[] =
{
    "Show animals",
    "Add animal",
    "Remove animal",
    "Sort animals by age",
    "Sort animals by year found",
    "Sort animals by sex",
    "Find animal",
    "Load file from disk",
    "Save administration to disk",
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

SPECIES getSpecies(void)
{
    return (SPECIES)getLimitedInt("enter species: ", SpeciesNames, 4);
}

SEX getSex(void)
{
    return (SEX)getLimitedInt("enter sex: ", SexNames, 2);
}

MenuOptions getMenuChoice(void)
{
    return (MenuOptions)getLimitedInt("choice: ", MenuStrings, 10);
}

DATE getDate(const char* message)
{
    DATE temp = {0, 0, 0};
    printf("%s", message);
    temp.Day = getInt("  enter day: ");
    temp.Month = getInt("  enter month: ");
    temp.Year = getInt("  enter year: ");
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

void printAnimals(const ANIMAL* animals, int nrAnimals)
{
    if (animals != NULL)
    {
        if (nrAnimals <= 0)
        {
            printf("\nAnimal array is empty, or nrAnimals is less than 0\n\n");
        }
        else
        {
            for (int i = 0; i < nrAnimals; i++)
            {
                printf("\nAnimal %d:\n", i+1);
                printf("Id:     %d\n", animals[i].Id);
                printf("Species:  %s\n", SpeciesNames[animals[i].Species]);
                printf("Sex:      %s\n", SexNames[animals[i].Sex]);
                printf("Age:      %d\n", animals[i].Age);
                printf("Animal was found:\n");
                printf("  at date:     %02d-%02d-%02d\n", animals[i].DateFound.Day, animals[i].DateFound.Month, animals[i].DateFound.Year);
            }
        }
    }
}
