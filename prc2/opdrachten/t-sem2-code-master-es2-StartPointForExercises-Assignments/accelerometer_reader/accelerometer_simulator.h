#ifndef ACCELEROMETER_SIMULATOR_H
#define ACCELEROMETER_SIMULATOR_H

#include "accelerometer.h"

void accelerometer_simulator_begin();

void accelerometer_simulator_set_measurement_mode();

void accelerometer_simulator_measure(accelerometer_data *data);

#endif
