#include <Arduino.h>
#include "showExtras.h"

//use a pointer to change a value to showcase the value has been stored in the pointer
void doCalcWithPointer(int value, int *result)
{
	int calcResult = value * 10 / 2;
	*result = calcResult;
}

//Use a struct for grading
VehicleData vehicleData;
void fillVehicleWithData(float speed, float flyingHeight, float fuelLeft)
{
	
	vehicleData.speed = speed;
	vehicleData.flyingHeight = flyingHeight;
	vehicleData.fuelLeft = fuelLeft;
}

void retrieveDataFromVehicle(float* speed, float* flyingHeight, float* fuelLeft)
{
	*speed = vehicleData.speed;
	*flyingHeight = vehicleData.flyingHeight;
	*fuelLeft = vehicleData.fuelLeft;
}