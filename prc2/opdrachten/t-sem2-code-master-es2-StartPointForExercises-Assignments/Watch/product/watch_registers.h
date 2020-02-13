#ifndef WATCH_REGISTERS_H
#define WATCH_REGISTERS_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "watch_registers.h"
#include "watch_i2c.h"

#define ADDRESS_CONFIG    (0x20)
#define ADDRESS_TIME_HIGH (0x21)
#define ADDRESS_TIME_LOW  (0x22)
#define ADDRESS_DATE_HIGH (0x23)
#define ADDRESS_DATE_LOW  (0x24)

typedef enum
{
	TIME_HOUR_MINUTE = 0,
	TIME_HOUR_MINUTE_SECOND = 1
}
time_format;

typedef enum {
	TIME_UPDATE_DISABLED = 0,
	TIME_EVERY_1_SECOND = 1,
	TIME_EVERY_30_SECONDS = 2,
	TIME_EVERY_MINUTE = 3
}
time_update_interval;

/*!
  * Update the configuration byte by toggling the pause bit.
  *
  * @param config: The address of the configuration byte that must be updated.
  *
  * @pre config may not be NULL.
  */
void watch_registers_toggle_config_is_paused(
  uint8_t *config);

/*!
  * Update the configuration byte by updating the time format.
  *
  * @param config: The address of the configuration byte that must be updated.
  * @param format: Time format setting.
  *
  * @pre config may not be NULL.
  */
void watch_registers_set_config_time_format(
  uint8_t *config,
  time_format format);

/*!
  * Update the configuration byte by updating the time update interval.
  *
  * @param config: The address of the configuration byte that must be updated.
  * @param interval: Time update interval setting.
  *
  * @pre config may not be NULL.
  */
void watch_registers_set_config_time_update_interval(
  uint8_t* config,
  time_update_interval interval);

/*!
  * Retrieve the configuration settings.
  *
  * @param config: The configuration byte.
  * @param is_paused: The address to which the is_paused setting will be written.
  * @param format: The address to which the time format will be written.
  * @param interval: The address to which the time update interval will be written.
  *
  * @pre is_paused, format and interval may not be NULL.
  */
void watch_registers_get_config_settings(
  uint8_t config,
  bool* is_paused,
  time_format* format,
  time_update_interval* interval);

/*!
  * Update the time bytes by updating the hours bits.
  *
  * @param time_bits_low: The address to which the updated LSB part
                          of the time will be written.
  * @param time_bits_high: The address to which the updated MSB part
                           of the time will be written.
  * @param hours: The hour part of the time.
  *
  * @pre time_bits_low and time_bits_high may not be NULL.
  */
void watch_registers_set_time_hours(
  uint8_t* time_bits_low,
  uint8_t* time_bits_high,
  uint8_t hours);

/*!
  * Update the time bytes by updating the minutes bits.
  *
  * @param time_bits_low: The address to which the updated LSB part
                          of the time will be written.
  * @param time_bits_high: The address to which the updated MSB part
                           of the time will be written.
  * @param minutes: The minute part of the time.
  *
  * @pre time_bits_low and time_bits_high may not be NULL.
  */
void watch_registers_set_time_minutes(
  uint8_t* time_bits_low,
  uint8_t* time_bits_high,
  uint8_t minutes);

/*!
  * Update the time bytes by updating the seconds bits.
  *
  * @param time_bits_low: The address to which the updated LSB part
                          of the time will be written.
  * @param time_bits_high: The address to which the updated MSB part
                           of the time will be written.
  * @param seconds: The seconds part of the time.
  *
  * @pre time_bits_low and time_bits_high may not be NULL.
  */
void watch_registers_set_time_seconds(
  uint8_t* time_bits_low,
  uint8_t* time_bits_high,
  uint8_t seconds);

/*!
  * Retrieve the time fields.
  *
  * @param time_bits_low: The LSB part of the time.
  * @param time_bits_high: The MSB part of the time.
  * @param hours: The address to which the hours will be written.
  * @param minutes: The address to which the minutes will be written.
  * @param seconds: The address to which the seconds will be written.
  *
  * @pre hours, minutes and seconds may not be NULL.
  */
void watch_registers_get_time(
  uint8_t time_bits_low,
  uint8_t time_bits_high,
	uint8_t* hours,
	uint8_t* minutes,
	uint8_t* seconds);

/*!
  * Update the date bytes by updating the year bits.
  *
  * @param date_bits_low: The address to which the updated LSB part
                          of the date will be written.
  * @param date_bits_high: The address to which the updated MSB part
                           of the date will be written.
  * @param year: The year part of the time.
  *
  * @pre date_bits_low and date_bits_high may not be NULL.
  */
void watch_registers_set_date_year(
  uint8_t* date_bits_low,
  uint8_t* date_bits_high,
	uint8_t year);

/*!
  * Update the date bytes by updating the month bits.
  *
  * @param date_bits_low: The address to which the updated LSB part
                          of the date will be written.
  * @param date_bits_high: The address to which the updated MSB part
                           of the date will be written.
  * @param month: The month part of the time.
  *
  * @pre date_bits_low and date_bits_high may not be NULL.
  */
void watch_registers_set_date_month(
  uint8_t* date_bits_low,
  uint8_t* date_bits_high,
	uint8_t month);

/*!
  * Update the date bytes by updating the day_of_month bits.
  *
  * @param date_bits_low: The address to which the updated LSB part
                          of the date will be written.
  * @param date_bits_high: The address to which the updated MSB part
                           of the date will be written.
  * @param day_of_month: The day_of_month part of the time.
  *
  * @pre date_bits_low and date_bits_high may not be NULL.
  */
void watch_registers_set_date_day_of_month(
  uint8_t* date_bits_low,
  uint8_t* date_bits_high,
	uint8_t day_of_month);

/*!
  * Retrieve the date fields.
  *
  * @param date_bits_low: The LSB part of the date.
  * @param date_bits_high: The MSB part of the date.
  * @param year: The address to which the year will be written.
  * @param month: The address to which the month will be written.
  * @param day_of_month: The address to which the day_of_month will be written.
  *
  * @pre year, month and day_of_month may not be NULL.
  */
void watch_registers_get_date(
  uint8_t date_bits_low,
  uint8_t date_bits_high,
	uint8_t* year,
	uint8_t* month,
	uint8_t* day_of_month);

#endif
