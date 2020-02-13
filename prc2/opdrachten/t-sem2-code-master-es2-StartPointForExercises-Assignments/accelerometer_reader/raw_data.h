#ifndef RAW_DATA_H
#define RAW_DATA_H

#define RAW_DATA_TIME_BETWEEN_MEASURMENTS_IN_MS (100)

typedef struct {
  float accelerationInMs2;
  float powerUseInKW;
} Measurement;

unsigned int raw_data_get_number_of_samples();
const Measurement* raw_data_get_sample(unsigned int index);

#endif
