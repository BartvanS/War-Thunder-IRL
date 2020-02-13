#include <stdlib.h>
#include <time.h>

#include "channel.h"
#include "parity.h"
#include "resource_detector.h"

void channel_init() {
  srand (time (NULL));	// take the current time as seed for random generator
}

uint8_t channel_change_one_random_bit(uint8_t value) {
    return value;
}
