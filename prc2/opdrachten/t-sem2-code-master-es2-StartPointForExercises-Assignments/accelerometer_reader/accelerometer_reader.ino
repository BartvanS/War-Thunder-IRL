#include <stdbool.h>

#include "accelerometer.h"

/* Here you can select the device you would like to use.
 *  Check out the acceleromter.h for the available options.
 */
accelerometer_device device = LSM6; //SIMULATOR;

bool useSimulationMode = (device == SIMULATOR);

#define DELAY_BETWEEN_MEASUREMENTS_IN_MS (250)

void setup() {
  Serial.begin(9600);
  accelerometer_begin(device);
  accelerometer_set_measurement_mode();
}

void printaccelerometerData(long measureStartTime, const accelerometer_data* data) {
  Serial.print("Time: "); Serial.print(millis() - measureStartTime); Serial.print(" [ms], ");
  Serial.print("X: "); Serial.print(data->x);
  Serial.print(",\tY: "); Serial.print(data->y);
  Serial.print(",\tZ: "); Serial.println(data->z);
}

void loop() {
  static long measureStartTime = 0;
  static accelerometer_data data;
  
  accelerometer_measure(&data);
  printaccelerometerData(measureStartTime, &data);

  if (useSimulationMode) {
    /* After some time the simulator device does not
        provide any non-zero data. Therefore we reset it,
        so it is restarted.
    */
   if (data.x == 0) {
      measureStartTime = millis();
      accelerometer_begin(device);
    }
  }
  
  delay(DELAY_BETWEEN_MEASUREMENTS_IN_MS);
}
