#include "watch_i2c.h"
#include "watch_device_simulator.h"

int watch_i2c_write_byte(uint8_t address, uint8_t value)
{
	return watch_device_simulator_write_byte(address,value);
}

int watch_i2c_read_byte(uint8_t address, uint8_t* value)
{
	return watch_device_simulator_read_byte(address,value);
}
