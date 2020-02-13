#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

typedef enum {
  MMA7455 = 0,
  LSM303 = 1,
  LSM6 = 2,
  SIMULATOR = 3
} accelerometer_device;

typedef struct {
  int16_t x;
  int16_t y;
  int16_t z;
} accelerometer_data;

void accelerometer_begin(accelerometer_device device);

void accelerometer_set_measurement_mode();

void accelerometer_measure(accelerometer_data *data);

#endif
