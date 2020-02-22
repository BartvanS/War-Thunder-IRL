#include "bike_math.h"
uint16_t bike_math_get_value_for_data_type(bike_store_measurement measurement, BIKE_DATA_TYPE_ENUM data_type)
{
	uint16_t value = 0;

	if(data_type == BIKE_CADENCE) {
		value = measurement.cadence;
	}
	else if(data_type == BIKE_SPEED) {
		value = measurement.speed;
	}
	else if(data_type == BIKE_HEART_RATE) {
		value = measurement.heart_rate;
	}
	else if(data_type == BIKE_POWER) {
		value = measurement.power;
	}

	return value;
}

uint16_t bike_math_calculate_min_value(BIKE_DATA_TYPE_ENUM data_type)
{
	uint16_t number_of_measurements = bike_store_get_number_of_measurements_present();

	uint16_t min_value = UINT16_MAX;

	for(uint16_t index_position = 0; index_position < number_of_measurements; index_position++)
	{
		bike_store_measurement measurement = bike_store_get_measurement(index_position);
		uint16_t value = bike_math_get_value_for_data_type(measurement, data_type);
		if(value < min_value)
		{
			min_value = value;
		}
	}

	return min_value;

}

uint16_t bike_math_calculate_max_value(BIKE_DATA_TYPE_ENUM data_type)
{
	uint16_t number_of_measurements = bike_store_get_number_of_measurements_present();

	uint16_t max_value = 0;

	for(uint16_t index_position = 0; index_position < number_of_measurements; index_position++)
	{
		bike_store_measurement measurement = bike_store_get_measurement(index_position);
		uint16_t value = bike_math_get_value_for_data_type(measurement, data_type);
		if(value > max_value)
		{
			max_value = value;
		}
	}

	return max_value;

}

uint16_t bike_math_calculate_average_value(BIKE_DATA_TYPE_ENUM data_type)
{
	uint16_t number_of_measurements = bike_store_get_number_of_measurements_present();

	if(number_of_measurements == 0) return 0;

	uint16_t average = 0;
	uint32_t sum = 0;

	for(uint16_t index_position = 0; index_position < number_of_measurements; index_position++)
	{
		bike_store_measurement measurement = bike_store_get_measurement(index_position);
		uint16_t value = bike_math_get_value_for_data_type(measurement, data_type);
		sum += value;
	}

	average = sum / number_of_measurements;

	return average;
}
