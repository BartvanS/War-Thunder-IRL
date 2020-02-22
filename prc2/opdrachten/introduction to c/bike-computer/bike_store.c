#include <stdio.h>
#include <stdlib.h>
#include "bike_store.h"

#define bike_store_MAX_NUMBER_MEASUREMENTS (32)
bike_store_measurement bike_store_array[bike_store_MAX_NUMBER_MEASUREMENTS] = {{0,},};
uint16_t bike_store_number_of_measurements_present = 0;
uint16_t bike_store_get_maximum_bike_store_size()
{
	return bike_store_MAX_NUMBER_MEASUREMENTS;
}

void bike_store_add_measurement(bike_store_measurement value)
{
	if(bike_store_number_of_measurements_present >=
		 bike_store_MAX_NUMBER_MEASUREMENTS)
	{
		bike_store_number_of_measurements_present = 0;
	}

	bike_store_array[bike_store_number_of_measurements_present] = value;
	bike_store_number_of_measurements_present++;
}

uint16_t bike_store_get_number_of_measurements_present()
{
	return bike_store_number_of_measurements_present;
}

bike_store_measurement bike_store_get_measurement(uint16_t index_position)
{
	bike_store_measurement value = bike_store_array[index_position];

	return value;
}
