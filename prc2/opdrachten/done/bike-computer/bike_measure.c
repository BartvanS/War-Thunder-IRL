#include "bike_measure.h"
#include <stdio.h>
#include <stdlib.h>
uint16_t bike_computer_simulator_get_random_value(uint16_t min_range, uint16_t max_range)
{
	uint16_t range = (max_range - min_range);

	uint16_t random_value = min_range +
							(rand() % range);

	return random_value;
}

uint16_t bike_measure_speed_in_kmh()
{
	return bike_computer_simulator_get_random_value(BIKE_COMPUTER_SIMULATOR_VALUE_MIN_SPEED,
													BIKE_COMPUTER_SIMULATOR_VALUE_MAX_SPEED);
}

uint16_t bike_measure_power_in_watt()
{
	return bike_computer_simulator_get_random_value(BIKE_COMPUTER_SIMULATOR_VALUE_MIN_POWER,
													BIKE_COMPUTER_SIMULATOR_VALUE_MAX_POWER);
}

uint16_t bike_measure_cadence_in_rpm()
{
	return bike_computer_simulator_get_random_value(BIKE_COMPUTER_SIMULATOR_VALUE_MIN_CADENCE,
													BIKE_COMPUTER_SIMULATOR_VALUE_MAX_CADENCE);
}

uint16_t bike_measure_heart_rate_in_bpm()
{
	return bike_computer_simulator_get_random_value(BIKE_COMPUTER_SIMULATOR_VALUE_MIN_HEART_RATE,
													BIKE_COMPUTER_SIMULATOR_VALUE_MAX_HEART_RATE);
}