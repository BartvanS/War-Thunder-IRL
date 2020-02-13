#ifndef ACCELEROMETER_MMA7455_H
#define ACCELEROMETER_MMA7455_H

#include "accelerometer.h"

void accelerometer_mma7455_begin();

void accelerometer_mma7455_set_measurement_mode();

void accelerometer_mma7455_measure(accelerometer_data *data);

#endif
