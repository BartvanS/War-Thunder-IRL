/*
 * animal_shelter.c
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
#include "file_element.h"
#include "animal.h"
#include "terminal_io.h"

const char *filename = "testFile";

static void addAnimalToAdministration(ANIMAL* animals, unsigned int arrayLength,\
                                      unsigned int* nrAnimalsPresent)
{
    // this function does not test the validity of input parameters as it is
    // a static function (equivalent to private in a C# class). Please do not
    // confuse this use of static with a static method in C#!
    ANIMAL animal = {1,0, 0, 0, {0, 0, 0}};

    animal.Id = getInt("enter animal Id: ");
    animal.Species = getSpecies();
    animal.Sex = getSex();
    animal.Age = getInt("enter age: ");
    animal.DateFound = getDate("enter found date:\n");

    int result = addAnimal(&animal, animals, arrayLength, *nrAnimalsPresent, nrAnimalsPresent);
    printf("\nAdd animal result: %s\n", result == 0 ? "success": "fail");
}

static void removeAnimalFromAdministration(ANIMAL* animals, unsigned int* nrAnimals)
{
    int animalId = getInt("enter animal id: ");

    int result = removeAnimal(animalId, animals, *nrAnimals, nrAnimals);
    printf("%d animals removed (-1 is error)\n", result);
}

static void findAndPrintAnimal(const ANIMAL* animals, int nrAnimals)
{
    ANIMAL animal = {1,0, 0, 0, {0, 0, 0}};

    int animalId = getInt("enter animal id: ");

    int result = findAnimalById(animalId, animals, nrAnimals, &animal);
    if (result == 1)
    {
        printAnimals(&animal, 1);
    }
    else if (result == 0)
    {
        printf("Find animal result: animalId %d not found\n", animalId);
    }
    else
    {
        printf("Find animal result: fail\n");
    }
}

static void addTestData(ANIMAL* animals, unsigned int* nrAnimals)
{
    ANIMAL a1 = {1,Dog, Male, 12, {1, 2, 3}};
    ANIMAL a2 = {2,Cat, Female, 4, {4, 3, 2}};
    ANIMAL a3 = {3,Parrot, Male, 40, {8, 9, 10}};
    ANIMAL a4 = {4,Dog, Female, 1, {1, 1, 100}};
    ANIMAL a5 = {5,GuineaPig, Male, 3, {3, 4, 1}};

    animals[(*nrAnimals)++] = a1;
    animals[(*nrAnimals)++] = a2;
    animals[(*nrAnimals)++] = a3;
    animals[(*nrAnimals)++] = a4;
    animals[(*nrAnimals)++] = a5;
}

int main (int argc, char * argv[])
{
    const unsigned int MaxNrAnimals = 20;
    // char filename[MAX_STRLEN] = "";
    ANIMAL animals[MaxNrAnimals];
    unsigned int nrAnimals = 0;
    MenuOptions choice = MO_ShowAnimals;

    addTestData(animals, &nrAnimals);

    printf ("PRC assignment 'Animal Shelter'\n"
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
            case MO_ShowAnimals:
                printAnimals(animals, nrAnimals);
                break;
            case MO_AddAnimal:
                addAnimalToAdministration(animals, MaxNrAnimals, &nrAnimals);
                break;
            case MO_RemoveAnimal:
                removeAnimalFromAdministration(animals, &nrAnimals);
                break;
            case MO_SortAnimalsByAge:
                {
                    int result = sortAnimalsByAge(animals, nrAnimals);
                    printf("Sort animal by age result: %s\n", result == 0 ? "success": "fail");
                }
                break;
            case MO_SortAnimalsByYearFound:
                {
                    int result = sortAnimalsByYearFound(animals, nrAnimals);
                    printf("Sort animal by year found result: %s\n", result == 0 ? "success": "fail");
                }
                break;
            case MO_SortAnimalsBySex:
                {
                    int result = sortAnimalsBySex(animals, nrAnimals);
                    printf("Sort animal by sex result: %s\n", result == 0 ? "success": "fail");
                }
                break;
            case MO_FindAnimal:
                findAndPrintAnimal(animals, nrAnimals);
                break;
        	  case MO_Save:
        		{
        			int result = writeAnimals(filename, animals, nrAnimals);
        			printf("Save animals to file result %s\n", result == 0 ? "success" : "fail");
        		}
        		break;
        	  case MO_Load:
        		{
        			nrAnimals = getNrAnimalsInFile(filename);
        			if(nrAnimals != -1)
        			{
        				nrAnimals = readAnimals(filename, animals, nrAnimals);
        			}
        			printf("Load animals from file result %s\n", nrAnimals != -1 ? "succes" : "fail");
        		}
        		break;             case MO_Quit:
                        // nothing to do here
                        break;
                    default:
                        printf ("ERROR: invalid choice: %d\n", choice);
                        break;
                }
            }
    return 0;
}
