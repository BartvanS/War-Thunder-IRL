#ifndef WATCH_I2C_H
#define WATCH_I2C_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

int watch_i2c_write_byte(uint8_t address, uint8_t value);
int watch_i2c_read_byte(uint8_t address, uint8_t* value);

#endif
