#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "animal.h"

/* pre    : animalArrayLength must be greater than numberOfAnimalsPresent
 * post   : animalArray is updated with the information from animalPtr, the updated number of animals is passed in newNumberOfAnimalsPresent
 * returns: 0 on success or -1 if an error occurs
 */
int addAnimal(const ANIMAL* animalPtr, ANIMAL* animalArray, unsigned int animalArrayLength, \
              unsigned int numberOfAnimalsPresent, unsigned int* newNumberOfAnimalsPresent);

/* pre    :
 * post   : All animals with id 'animalId' are removed from AnimalArray, the updated number of animals is passed in newNumberOfAnimalsPresent
 * returns: The number of removed animals, 0 if no animals removed or -1 if an error occurs
 */
int removeAnimal(int animalId, ANIMAL* animalArray, unsigned int numberOfAnimalsPresent, unsigned int* newNumberOfAnimalsPresent);

/* pre    :
 * post   : The first animal from animalArray with id 'animalId' is copied into animalPtr
 * returns: 1 on success, 0 if not found or -1 if an error occurs
 */
int findAnimalById(int animalId, const ANIMAL* animalArray, unsigned int numberOfAnimalsPresent, ANIMAL* animalPtr);

/* pre    :
 * post   : All animals in animalArray are sorted by age
 * returns: 0 on success or -1 if an error occurs
 */
int sortAnimalsByAge(ANIMAL* animalArray, unsigned int numberOfAnimalsPresent);

/* pre    :
 * post   : All animals in animalArray are sorted by the year in which they were found
 * returns: 0 on success or -1 if an error occurs
 */
int sortAnimalsByYearFound(ANIMAL* animalArray, unsigned int numberOfAnimalsPresent);

/* pre    :
 * post   : All animals in animalArray are sorted: first female animals and then male animals
 * returns: 0 on success or -1 if an error occurs
 */
int sortAnimalsBySex(ANIMAL *animalArray, unsigned int numberOfAnimalsPresent);

#endif
