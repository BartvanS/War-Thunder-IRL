#ifndef WATCH_H
#define WATCH_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "watch_registers.h"

int watch_config_reset();
int watch_config_toggle_pause();
int watch_config_set_time_format(time_format format);
int watch_config_set_time_update_interval(time_update_interval interval);
int watch_config_get_settings(
	bool *is_paused,
	time_format* format,
	time_update_interval *interval);

int watch_set_time_hours(uint8_t hours);
int watch_set_time_minutes(uint8_t minutes);
int watch_set_time_seconds(uint8_t seconds);
int watch_get_time(uint8_t* hours, uint8_t* minutes, uint8_t* seconds);

int watch_set_date_year(uint16_t year);
int watch_set_date_month(uint8_t month);
int watch_set_date_day_of_month(uint8_t day_of_month);
int watch_get_date(uint8_t *year,
									 uint8_t* month,
									 uint8_t* day_of_month);

#endif
