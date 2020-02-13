#include <Arduino.h>

#include "accelerometer_simulator.h"
#include "raw_data.h"

long startTime = 0;
float randomAccelerationDeltaInMs2 = 0;

void accelerometer_simulator_begin() {
  Serial.println("Initialised!");
  
  startTime = millis();
  randomSeed(startTime);

  const Measurement* measurement = raw_data_get_sample(0);
  
  randomAccelerationDeltaInMs2 = \
      0.25*measurement->accelerationInMs2*random(-50,51)/100;
}

void accelerometer_simulator_set_measurement_mode() {
  //Do nothing...
}

void accelerometer_simulator_measure(accelerometer_data *data) {
  float accelerationInMs2 = 0;
  
  int calculated_index = (millis() - startTime) / RAW_DATA_TIME_BETWEEN_MEASURMENTS_IN_MS;
  int number_of_samples = raw_data_get_number_of_samples();

  if(calculated_index >= number_of_samples) {
    data->x = data->y = data->z = 0;
    return;
  }

  const Measurement* measurement = raw_data_get_sample(calculated_index);

  accelerationInMs2 = measurement->accelerationInMs2;
  accelerationInMs2 += randomAccelerationDeltaInMs2;

  data->x = accelerationInMs2 * 1000;
  data->y = 0;
  data->z = 0;
}

