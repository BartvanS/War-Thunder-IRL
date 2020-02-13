#include "animal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// Note: make sure to set 'resource_detector.h' as the last include.
#include "resource_detector.h"


int addAnimal(const ANIMAL* animalPtr, ANIMAL* animalArray, unsigned int animalArrayLength, \
              unsigned int numberOfAnimalsPresent, unsigned int* newNumberOfAnimalsPresent) 
{
	return -1;
}

int removeAnimal(int animalId, ANIMAL* animalArray, unsigned int numberOfAnimalsPresent,
                unsigned int* newNumberOfAnimalsPresent) 
{
 	return -1;
}

int findAnimalById(int animalId, const ANIMAL* animalArray, unsigned int numberOfAnimalsPresent,
                    ANIMAL* animalPtr)
{
 	return -1;
}

/*-------------------------------------------------------------------------------*/
int sortAnimalsByAge(ANIMAL* animalArray, unsigned int numberOfAnimalsPresent)
{
	return 0;
}

int sortAnimalsByYearFound(ANIMAL* animalArray, unsigned int numberOfAnimalsPresent)
{
	return 0;
}

int sortAnimalsBySex(ANIMAL *animalArray, unsigned int numberOfAnimalsPresent)
{
	return 0;
}
