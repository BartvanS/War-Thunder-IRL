#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include <resource_detector.h>
#include "watch.h"
#include "watch_device_simulator.h"

//#define ONE_SECOND (1000*1000)
#define ONE_SECOND (1*1000)

int main (int argc, char * argv[])
{
  uint8_t hours = 11, minutes = 55, seconds = 42;

  watch_set_time_hours(hours);
  watch_set_time_minutes(minutes);
  watch_set_time_seconds(seconds);

  while(true)
  {
    watch_get_time(&hours,&minutes,&seconds);
    watch_device_simulator_print_time(hours,minutes,seconds);

    uint8_t number_seconds_update = 10;
    watch_device_simulator_increase_time(number_seconds_update);
    usleep(ONE_SECOND * number_seconds_update);
  }

  return 0;
}
