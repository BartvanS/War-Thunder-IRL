#include <stdint.h>
#include <stdio.h>

#include "watch_device_simulator.h"
#include "watch_registers.h"
#include "watch_i2c.h"

uint8_t register_values[5];

int _watch_device_simulator_address_to_array_index(
	uint8_t address,
	uint8_t* register_value_index)
{
	if(register_value_index == NULL) return -1;

	if((address < ADDRESS_CONFIG) || (address > ADDRESS_DATE_HIGH)) {
		return -1;
	}

	*register_value_index = address - ADDRESS_CONFIG;

	return 0;
}

int watch_device_simulator_write_byte(uint8_t address, uint8_t value)
{
	uint8_t index = 0;
	if( _watch_device_simulator_address_to_array_index(address, &index) != 0)
	{
		return -1;
	}

	register_values[index] = value;

	return 0;
}

int watch_device_simulator_read_byte(uint8_t address, uint8_t* value)
{
	uint8_t index = 0;
	if( _watch_device_simulator_address_to_array_index(address, &index) != 0)
	{
		return -1;
	}

	*value = register_values[index];

	return 0;
}

void _watch_device_simulator_add_one_second(
	uint8_t* hours,
	uint8_t* minutes,
	uint8_t* seconds)
{
	*seconds += 1;

	if(*seconds == 60)
	{
		*seconds = 0;
		*minutes += 1;
		if(*minutes == 60)
		{
			*minutes = 0;
			*hours += 1;
			if(*hours == 12)
			{
				*hours = 0;
			}
		}
	}
}

void watch_device_simulator_print_time(
	uint8_t hours,
	uint8_t minutes,
	uint8_t seconds)
{
		printf("Time: %02d:%02d:%02d\n", hours, minutes, seconds);
}

int watch_device_simulator_increase_time(uint8_t number_of_seconds)
{
	uint8_t time_bits_low, time_bits_high = 0;
	watch_device_simulator_read_byte(ADDRESS_TIME_LOW, &time_bits_low);
	watch_device_simulator_read_byte(ADDRESS_TIME_HIGH, &time_bits_high);

	uint8_t seconds = 0, minutes = 0, hours = 0;
	watch_registers_get_time(time_bits_low, time_bits_high, &hours, &minutes, &seconds);

	for(uint8_t i = 0; i < number_of_seconds; i++)
	{
		_watch_device_simulator_add_one_second(&hours,&minutes,&seconds);
	}

	watch_registers_set_time_hours(&time_bits_low, &time_bits_high, hours);
	watch_registers_set_time_minutes(&time_bits_low, &time_bits_high, minutes);
	watch_registers_set_time_seconds(&time_bits_low, &time_bits_high, seconds);

	watch_device_simulator_write_byte(ADDRESS_TIME_LOW, time_bits_low);
	watch_device_simulator_write_byte(ADDRESS_TIME_HIGH, time_bits_high);

	return 0;
}
