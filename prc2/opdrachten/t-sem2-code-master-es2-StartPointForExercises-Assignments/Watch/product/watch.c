#include "watch.h"
#include "watch_registers.h"
#include "watch_i2c.h"

/*----------------------------------------------------------------------------*/
/*     C O N F I G                                                            */
/*----------------------------------------------------------------------------*/
int watch_config_reset()
{
  uint8_t config = 0;
  if(watch_i2c_write_byte(ADDRESS_CONFIG, config) != 0) return -1;
  return 0;
}

int watch_config_toggle_pause()
{
  uint8_t config;
  if(watch_i2c_read_byte(ADDRESS_CONFIG, &config) != 0) return -1;
  watch_registers_toggle_config_is_paused(&config);
  if(watch_i2c_write_byte(ADDRESS_CONFIG, config) != 0) return -1;

  return 0;
}

int watch_config_set_time_format(time_format format)
{
  uint8_t config;
  if(watch_i2c_read_byte(ADDRESS_CONFIG, &config) != 0) return -1;
  watch_registers_set_config_time_format(&config, format);
  if(watch_i2c_write_byte(ADDRESS_CONFIG, config) != 0) return -1;

  return 0;
}

int watch_config_set_time_update_interval(time_update_interval interval)
{
  uint8_t config;
  if(watch_i2c_read_byte(ADDRESS_CONFIG, &config) != 0) return -1;
  watch_registers_set_config_time_update_interval(&config, interval);
  if(watch_i2c_write_byte(ADDRESS_CONFIG, config) != 0) return -1;

  return 0;
}

int watch_config_get_settings(
  bool *is_paused,
	time_format* format,
	time_update_interval *interval)
{
  uint8_t config;

  if(is_paused == NULL || format == NULL || interval == NULL) return -1;

  if(watch_i2c_read_byte(ADDRESS_CONFIG, &config) != 0) return -1;
  watch_registers_get_config_settings(config, is_paused, format, interval);

  return 0;
}

/*----------------------------------------------------------------------------*/
/*     T I M E                                                                */
/*----------------------------------------------------------------------------*/
int watch_set_time_hours(uint8_t hours)
{
  uint8_t time_bits_low, time_bits_high;

  if(watch_i2c_read_byte(ADDRESS_TIME_LOW, &time_bits_low) != 0) return -1;
  if(watch_i2c_read_byte(ADDRESS_TIME_HIGH, &time_bits_high) != 0) return -1;
  watch_registers_set_time_hours(&time_bits_low, &time_bits_high, hours);

  if(watch_i2c_write_byte(ADDRESS_TIME_LOW, time_bits_low) != 0) return -1;
  if(watch_i2c_write_byte(ADDRESS_TIME_HIGH, time_bits_high) != 0) return -1;

    return 0;
}

int watch_set_time_minutes(uint8_t minutes)
{
  uint8_t time_bits_low, time_bits_high;

  if(watch_i2c_read_byte(ADDRESS_TIME_LOW, &time_bits_low) != 0) return -1;
  if(watch_i2c_read_byte(ADDRESS_TIME_HIGH, &time_bits_high) != 0) return -1;

  watch_registers_set_time_minutes(&time_bits_low, &time_bits_high,minutes);

  if(watch_i2c_write_byte(ADDRESS_TIME_LOW, time_bits_low) != 0) return -1;
  if(watch_i2c_write_byte(ADDRESS_TIME_HIGH, time_bits_high) != 0) return -1;

  return 0;
}

int watch_set_time_seconds(uint8_t seconds)
{
  uint8_t time_bits_low, time_bits_high;

  if(watch_i2c_read_byte(ADDRESS_TIME_LOW, &time_bits_low) != 0) return -1;
  if(watch_i2c_read_byte(ADDRESS_TIME_HIGH, &time_bits_high) != 0) return -1;

  watch_registers_set_time_seconds(&time_bits_low, &time_bits_high, seconds);

  if(watch_i2c_write_byte(ADDRESS_TIME_LOW, time_bits_low) != 0) return -1;
  if(watch_i2c_write_byte(ADDRESS_TIME_HIGH, time_bits_high) != 0) return -1;

  return 0;
}

int watch_get_time(uint8_t* hours, uint8_t* minutes, uint8_t* seconds)
{
  uint8_t time_bits_low, time_bits_high;

  if(hours == NULL || minutes == NULL || seconds == NULL) return -1;

  if(watch_i2c_read_byte(ADDRESS_TIME_LOW, &time_bits_low) != 0) return -1;
  if(watch_i2c_read_byte(ADDRESS_TIME_HIGH, &time_bits_high) != 0) return -1;

  watch_registers_get_time(time_bits_low, time_bits_high,
                           hours, minutes,seconds);

  return 0;
}

/*----------------------------------------------------------------------------*/
/*     D A T E                                                                */
/*----------------------------------------------------------------------------*/
int watch_set_date_year(uint16_t year)
{
  uint8_t date_bits_low, date_bits_high;

  if(watch_i2c_read_byte(ADDRESS_DATE_LOW, &date_bits_low) != 0) return -1;
  if(watch_i2c_read_byte(ADDRESS_DATE_HIGH, &date_bits_high) != 0) return -1;

  watch_registers_set_date_year(&date_bits_low, &date_bits_low, year);

  if(watch_i2c_write_byte(ADDRESS_DATE_LOW, date_bits_low) != 0) return -1;
  if(watch_i2c_write_byte(ADDRESS_DATE_HIGH, date_bits_high) != 0) return -1;

  return 0;
}

int watch_set_date_month(uint8_t month)
{
  uint8_t date_bits_low, date_bits_high;

  if(watch_i2c_read_byte(ADDRESS_DATE_LOW, &date_bits_low) != 0) return -1;
  if(watch_i2c_read_byte(ADDRESS_DATE_HIGH, &date_bits_high) != 0) return -1;

  watch_registers_set_date_month(&date_bits_low, &date_bits_low, month);

  if(watch_i2c_write_byte(ADDRESS_DATE_LOW, date_bits_low) != 0) return -1;
  if(watch_i2c_write_byte(ADDRESS_DATE_HIGH, date_bits_high) != 0) return -1;

  return 0;
}

int watch_set_date_day_of_month(uint8_t day_of_month)
{
  uint8_t date_bits_low, date_bits_high;

  if(watch_i2c_read_byte(ADDRESS_DATE_LOW, &date_bits_low) != 0) return -1;
  if(watch_i2c_read_byte(ADDRESS_DATE_HIGH, &date_bits_high) != 0) return -1;

  watch_registers_set_date_day_of_month(&date_bits_low, &date_bits_low, day_of_month);

  if(watch_i2c_write_byte(ADDRESS_DATE_LOW, date_bits_low) != 0) return -1;
  if(watch_i2c_write_byte(ADDRESS_DATE_HIGH, date_bits_high) != 0) return -1;

  return 0;
}

int watch_get_date(uint8_t *year,
									 uint8_t* month,
									 uint8_t* day_of_month)
{
  uint8_t date_bits_low, date_bits_high;

  if(year == NULL || month == NULL || day_of_month == NULL) return -1;

  if(watch_i2c_read_byte(ADDRESS_DATE_LOW, &date_bits_low) != 0) return -1;
  if(watch_i2c_read_byte(ADDRESS_DATE_HIGH, &date_bits_high) != 0) return -1;

  watch_registers_get_date(date_bits_low, date_bits_low,
                           year, month, day_of_month);

  return 0;
}
