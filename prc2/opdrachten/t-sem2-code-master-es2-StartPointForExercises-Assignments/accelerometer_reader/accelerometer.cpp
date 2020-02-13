#include <Wire.h>
#include <Arduino.h>
#include "accelerometer.h"

#include "accelerometer_mma7455.h"
#include "accelerometer_lsm303.h"
#include "accelerometer_lsm6.h"
#include "accelerometer_simulator.h"

/* The given code below use function-pointers for 
 *  configuration the device we would like to use.
 */
typedef struct {
  void (*begin)();
  void (*set_measurement_mode)();
  void (*measure)(accelerometer_data *data);
} accelerometer_methods;

accelerometer_methods accelerometers[] = {
  {
    accelerometer_mma7455_begin,
    accelerometer_mma7455_set_measurement_mode,
    accelerometer_mma7455_measure
  },
  {
    accelerometer_lsm303_begin,
    accelerometer_lsm303_set_measurement_mode,
    accelerometer_lsm303_measure
  },
  {
    accelerometer_lsm6_begin,
    accelerometer_lsm6_set_measurement_mode,
    accelerometer_lsm6_measure
  },
  { accelerometer_simulator_begin,
    accelerometer_simulator_set_measurement_mode,
    accelerometer_simulator_measure
  }
};

accelerometer_methods* selected_device = &accelerometers[SIMULATOR];

void accelerometer_begin(accelerometer_device device) {
  selected_device = &accelerometers[device];
  selected_device->begin();
}

void accelerometer_set_measurement_mode() {
  selected_device->set_measurement_mode();
}

void accelerometer_measure(accelerometer_data *data) {
  selected_device->measure(data);
}

