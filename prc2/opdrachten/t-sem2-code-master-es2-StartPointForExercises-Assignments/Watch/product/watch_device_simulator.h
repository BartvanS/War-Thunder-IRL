#ifndef WATCH_DEVICE_SIMULATOR_H
#define WATCH_DEVICE_SIMULATOR_H

#include <stdint.h>

int watch_device_simulator_write_byte(uint8_t address, uint8_t value);
int watch_device_simulator_read_byte(uint8_t address, uint8_t* value);

int watch_device_simulator_increase_time(uint8_t number_of_seconds);
void watch_device_simulator_print_time(uint8_t hours, uint8_t minutes, uint8_t seconds);

#endif
