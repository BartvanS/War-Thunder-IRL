#ifndef BIKE_MATH_H
#define BIKE_MATH_H
#include <stdint.h>
#include "bike_store.h"
typedef enum
{
	BIKE_SPEED,
	BIKE_HEART_RATE,
	BIKE_CADENCE,
	BIKE_POWER
} BIKE_DATA_TYPE_ENUM;
uint16_t bike_math_get_value_for_data_type(bike_store_measurement measurement, BIKE_DATA_TYPE_ENUM data_type);
uint16_t bike_math_calculate_min_value(BIKE_DATA_TYPE_ENUM data_type);
uint16_t bike_math_calculate_max_value(BIKE_DATA_TYPE_ENUM data_type);
uint16_t bike_math_calculate_average_value(BIKE_DATA_TYPE_ENUM data_type);

#endif