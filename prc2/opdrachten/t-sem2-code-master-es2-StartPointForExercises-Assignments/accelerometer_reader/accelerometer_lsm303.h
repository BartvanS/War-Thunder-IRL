#ifndef ACCELEROMETER_LSM303_H
#define ACCELEROMETER_LSM303_H

#include "accelerometer.h"

void accelerometer_lsm303_begin();

void accelerometer_lsm303_set_measurement_mode();

void accelerometer_lsm303_measure(accelerometer_data *data);

#endif
