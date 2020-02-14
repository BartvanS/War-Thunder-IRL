/*
 * WashingProgram_shelter.c
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
#include "washingmachine.h"
#include "terminal_io.h"

static void addWashingProgramToAdministration(WashingProgram* WashingPrograms, unsigned int arrayLength,\
                                      unsigned int* nrWashingProgramsPresent)
{
    // this function does not test the validity of input parameters as it is
    // a static function (equivalent to private in a C# class). Please do not
    // confuse this use of static with a static method in C#!
    WashingProgram WashingProgram; // = {1,0, 0, 0, {0, 0, 0}};

    /*
    WashingProgram.Id = getInt("enter WashingProgram Id: ");
    WashingProgram.Species = getSpecies();
    WashingProgram.Sex = getSex();
    WashingProgram.Age = getInt("enter age: ");
    WashingProgram.DateFound = getDate("enter found date:\n");
    */

    int result = addWashingProgram(&WashingProgram, WashingPrograms, arrayLength, *nrWashingProgramsPresent, nrWashingProgramsPresent);
    printf("\nAdd WashingProgram result: %s\n", result == 0 ? "success": "fail");
}

static void removeWashingProgramFromAdministration(WashingProgram* WashingPrograms, unsigned int* nrWashingPrograms)
{
    int WashingProgramId = getInt("enter WashingProgram id: ");

    int result = removeWashingProgram(WashingProgramId, WashingPrograms, *nrWashingPrograms, nrWashingPrograms);
    printf("%d WashingPrograms removed (-1 is error)\n", result);
}

static void findAndPrintWashingProgram(const WashingProgram* WashingPrograms, int nrWashingPrograms)
{
    WashingProgram WashingProgram; // = {1,0, 0, 0, {0, 0, 0}};

    int WashingProgramId = getInt("enter WashingProgram id: ");

    int result = findWashingProgramById(WashingProgramId, WashingPrograms, nrWashingPrograms, &WashingProgram);
    if (result == 1)
    {
        printWashingPrograms(&WashingProgram, 1);
    }
    else if (result == 0)
    {
        printf("Find WashingProgram result: WashingProgramId %d not found\n", WashingProgramId);
    }
    else
    {
        printf("Find WashingProgram result: fail\n");
    }
}

static void addTestData(WashingProgram* WashingPrograms, unsigned int* nrWashingPrograms)
{
    WashingProgram a1; // = {1,Dog, Male, 12, {1, 2, 3}};
    WashingProgram a2; // = {2,Cat, Female, 4, {4, 3, 2}};
    WashingProgram a3; // = {3,Parrot, Male, 40, {8, 9, 10}};
    WashingProgram a4; // = {4,Dog, Female, 1, {1, 1, 100}};
    WashingProgram a5; // = {5,GuineaPig, Male, 3, {3, 4, 1}};

    WashingPrograms[(*nrWashingPrograms)++] = a1;
    WashingPrograms[(*nrWashingPrograms)++] = a2;
    WashingPrograms[(*nrWashingPrograms)++] = a3;
    WashingPrograms[(*nrWashingPrograms)++] = a4;
    WashingPrograms[(*nrWashingPrograms)++] = a5;
}

int main (int argc, char * argv[])
{
    const unsigned int MaxNrWashingPrograms = 20;
    WashingProgram WashingPrograms[MaxNrWashingPrograms];
    unsigned int nrWashingPrograms = 0;
    MenuOptions choice = MO_ShowWashingPrograms;

    addTestData(WashingPrograms, &nrWashingPrograms);

    printf ("PRC assignment 'WashingProgram Shelter'\n"
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
            case MO_ShowWashingPrograms:
                printWashingPrograms(WashingPrograms, nrWashingPrograms);
                break;
            case MO_AddWashingProgram:
                addWashingProgramToAdministration(WashingPrograms, MaxNrWashingPrograms, &nrWashingPrograms);
                break;
            case MO_RemoveWashingProgram:
                removeWashingProgramFromAdministration(WashingPrograms, &nrWashingPrograms);
                break;
            case MO_FindWashingProgram:
                findAndPrintWashingProgram(WashingPrograms, nrWashingPrograms);
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
