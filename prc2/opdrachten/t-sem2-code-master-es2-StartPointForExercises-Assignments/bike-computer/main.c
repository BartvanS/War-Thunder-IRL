#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

/*---------------------------------------------------------------*/
#define BIKE_COMPUTER_SIMULATOR_VALUE_MIN_SPEED (27)
#define BIKE_COMPUTER_SIMULATOR_VALUE_MAX_SPEED (30)

#define BIKE_COMPUTER_SIMULATOR_VALUE_MIN_POWER (150)
#define BIKE_COMPUTER_SIMULATOR_VALUE_MAX_POWER (200)

#define BIKE_COMPUTER_SIMULATOR_VALUE_MIN_HEART_RATE (130)
#define BIKE_COMPUTER_SIMULATOR_VALUE_MAX_HEART_RATE (140)

#define BIKE_COMPUTER_SIMULATOR_VALUE_MIN_CADENCE (88)
#define BIKE_COMPUTER_SIMULATOR_VALUE_MAX_CADENCE  (98)

#define bike_store_MAX_NUMBER_MEASUREMENTS (32)

typedef enum
{
	BIKE_SPEED,
	BIKE_HEART_RATE,
	BIKE_CADENCE,
	BIKE_POWER
} BIKE_DATA_TYPE_ENUM;

typedef struct
{
	uint16_t speed;
	uint16_t heart_rate;
	uint16_t cadence;
	uint16_t power;
} bike_store_measurement;

bike_store_measurement bike_store_array[bike_store_MAX_NUMBER_MEASUREMENTS] = {{0,},};
uint16_t bike_store_number_of_measurements_present = 0;

/*---------------------------------------------------------------*/
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

/*---------------------------------------------------------------*/
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

/*---------------------------------------------------------------*/
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

/*---------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	bike_store_measurement measurement;
	uint16_t min = 0, max = 0, average = 0;
	BIKE_DATA_TYPE_ENUM data_type;

	while(true)
	{
			measurement.speed = bike_measure_speed_in_kmh();
			measurement.cadence = bike_measure_cadence_in_rpm();
			measurement.heart_rate = bike_measure_heart_rate_in_bpm();
			measurement.power = bike_measure_power_in_watt();

			bike_store_add_measurement(measurement);

			data_type = BIKE_SPEED;
			min = bike_math_calculate_min_value(data_type);
			max = bike_math_calculate_max_value(data_type);
			average = bike_math_calculate_average_value(data_type);
			printf("SPEED:\t\t%d, average = %d, min = %d, max = %d [km/h]\n", measurement.speed,average,min,max);

			data_type = BIKE_CADENCE;
			min = bike_math_calculate_min_value(data_type);
			max = bike_math_calculate_max_value(data_type);
			average = bike_math_calculate_average_value(data_type);
			printf("CADENCE:\t%d, average = %d, min = %d, max = %d [rpm]\n", measurement.cadence,average,min,max);

			data_type = BIKE_HEART_RATE;
			min = bike_math_calculate_min_value(data_type);
			max = bike_math_calculate_max_value(data_type);
			average = bike_math_calculate_average_value(data_type);
			printf("HEART-RATE:\t%d, average = %d, min = %d, max = %d [hrm]\n", measurement.heart_rate,average,min,max);

			data_type = BIKE_POWER;
			min = bike_math_calculate_min_value(data_type);
			max = bike_math_calculate_max_value(data_type);
			average = bike_math_calculate_average_value(data_type);
			printf("POWER:\t\t%d, average = %d, min = %d, max = %d [watt]\n", measurement.power,average,min,max);
			printf("\n");

			sleep(1);
	}
}
