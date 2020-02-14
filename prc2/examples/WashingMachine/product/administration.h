#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "washingmachine.h"

/* pre    : WashingProgramArrayLength must be greater than numberOfWashingProgramsPresent
 * post   : WashingProgramArray is updated with the information from WashingProgramPtr, the updated number of WashingPrograms is passed in newNumberOfWashingProgramsPresent
 * returns: 0 on success or -1 if an error occurs
 */
int addWashingProgram(const WashingProgram* WashingProgramPtr, WashingProgram* WashingProgramArray, unsigned int WashingProgramArrayLength, \
              unsigned int numberOfWashingProgramsPresent, unsigned int* newNumberOfWashingProgramsPresent);

/* pre    :
 * post   : All WashingPrograms with id 'WashingProgramId' are removed from WashingProgramArray, the updated number of WashingPrograms is passed in newNumberOfWashingProgramsPresent
 * returns: The number of removed WashingPrograms, 0 if no WashingPrograms removed or -1 if an error occurs
 */
int removeWashingProgram(int WashingProgramId, WashingProgram* WashingProgramArray, unsigned int numberOfWashingProgramsPresent, unsigned int* newNumberOfWashingProgramsPresent);

/* pre    :
 * post   : The first WashingProgram from WashingProgramArray with id 'WashingProgramId' is copied into WashingProgramPtr
 * returns: 1 on success, 0 if not found or -1 if an error occurs
 */
int findWashingProgramById(int WashingProgramId, const WashingProgram* WashingProgramArray, unsigned int numberOfWashingProgramsPresent, WashingProgram* WashingProgramPtr);



#endif
