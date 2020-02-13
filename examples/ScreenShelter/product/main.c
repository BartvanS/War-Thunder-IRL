/*
 * Screen_shelter.c
 *
 *  Created on: August 31, 2016
 *      Author: Freddy Hurkmans
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "resource_detector.h"
#include "administration.h"
#include "screen.h"
#include "terminal_io.h"

static void addScreenToAdministration(Screen* Screens, unsigned int arrayLength,\
                                      unsigned int* nrScreensPresent)
{
    // this function does not test the validity of input parameters as it is
    // a static function (equivalent to private in a C# class). Please do not
    // confuse this use of static with a static method in C#!
    Screen Screen; // = {1,0, 0, 0, {0, 0, 0}};

    /*
    Screen.Id = getInt("enter Screen Id: ");
    Screen.Species = getSpecies();
    Screen.Sex = getSex();
    Screen.Age = getInt("enter age: ");
    Screen.DateFound = getDate("enter found date:\n");
    */

    int result = addScreen(&Screen, Screens, arrayLength, *nrScreensPresent, nrScreensPresent);
    printf("\nAdd Screen result: %s\n", result == 0 ? "success": "fail");
}

static void removeScreenFromAdministration(Screen* Screens, unsigned int* nrScreens)
{
    int ScreenId = getInt("enter Screen id: ");

    int result = removeScreen(ScreenId, Screens, *nrScreens, nrScreens);
    printf("%d Screens removed (-1 is error)\n", result);
}

static void findAndPrintScreen(const Screen* Screens, int nrScreens)
{
    Screen Screen; // = {1,0, 0, 0, {0, 0, 0}};

    int ScreenId = getInt("enter Screen id: ");

    int result = findScreenById(ScreenId, Screens, nrScreens, &Screen);
    if (result == 1)
    {
        printScreens(&Screen, 1);
    }
    else if (result == 0)
    {
        printf("Find Screen result: ScreenId %d not found\n", ScreenId);
    }
    else
    {
        printf("Find Screen result: fail\n");
    }
}

static void addTestData(Screen* Screens, unsigned int* nrScreens)
{
    Screen a1; // = {1,Dog, Male, 12, {1, 2, 3}};
    Screen a2; // = {2,Cat, Female, 4, {4, 3, 2}};
    Screen a3; // = {3,Parrot, Male, 40, {8, 9, 10}};
    Screen a4; // = {4,Dog, Female, 1, {1, 1, 100}};
    Screen a5; // = {5,GuineaPig, Male, 3, {3, 4, 1}};

    Screens[(*nrScreens)++] = a1;
    Screens[(*nrScreens)++] = a2;
    Screens[(*nrScreens)++] = a3;
    Screens[(*nrScreens)++] = a4;
    Screens[(*nrScreens)++] = a5;
}

int main (int argc, char * argv[])
{
    const unsigned int MaxNrScreens = 20;
    Screen Screens[MaxNrScreens];
    unsigned int nrScreens = 0;
    MenuOptions choice = MO_ShowScreens;

    addTestData(Screens, &nrScreens);

    printf ("PRC assignment 'Screen Shelter'\n"
            "-------------------------------------------");

    if (argc != 1)
    {
        fprintf (stderr, "%s: argc=%d\n", argv[0], argc);
    }

    while (choice != MO_Quit)
    {
        printf ("\n\nMENU\n====\n\n");
        choice = getMenuChoice();

        switch (choice)
        {
            // case MO_SelectFile:
            //     getStr("enter administration filename: ", filename, MAX_STRLEN);
            //     break;
            case MO_ShowScreens:
                printScreens(Screens, nrScreens);
                break;
            case MO_AddScreen:
                addScreenToAdministration(Screens, MaxNrScreens, &nrScreens);
                break;
            case MO_RemoveScreen:
                removeScreenFromAdministration(Screens, &nrScreens);
                break;
            case MO_FindScreen:
                findAndPrintScreen(Screens, nrScreens);
                break;
            case MO_Quit:
                // nothing to do here
                break;
            default:
                printf ("ERROR: invalid choice: %d\n", choice);
                break;
                }
            }
    return 0;
}
