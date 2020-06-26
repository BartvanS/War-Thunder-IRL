#ifndef SHOW_EXTRAS
#define SHOW_EXTRAS
void doCalcWithPointer(int value, int *result);

struct VehicleData
{
	float speed;
	float flyingHeight;
	float fuelLeft;
};
void fillVehicleWithData(float speed, float flyingHeight, float fuelLeft);

void retrieveDataFromVehicle(float* speed, float* flyingHeight, float* fuelLeft);

#endif