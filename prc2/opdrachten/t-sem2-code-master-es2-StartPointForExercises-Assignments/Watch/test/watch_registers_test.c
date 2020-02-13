#include <string.h>
#include <stdio.h>

#include "resource_detector.h"
#include "watch_registers.h"
#include "unity.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

uint8_t hours, minutes, seconds;
uint8_t year, month, day_of_month;
uint8_t time_bits_low, time_bits_high;
uint8_t date_bits_low, date_bits_high;

uint16_t combine(uint8_t low, uint8_t high) {
  return (high << 8) | low;
}

void setUp(void)
{
  time_bits_low = 0;
  time_bits_high = 0;
  hours = 11;
  minutes = 55;
  seconds = 42;

  date_bits_low = 0;
  date_bits_high = 0;
  year = 108;
  month = 11;
  day_of_month = 30;
}

void tearDown(void)
{
    // This is run after EACH test
}

void test_setting_time_hours(void)
{
    watch_registers_set_time_hours(&time_bits_low, &time_bits_high, hours);
    TEST_ASSERT_EQUAL(hours << 12, combine(time_bits_low, time_bits_high));
}

void test_setting_time()
{
  watch_registers_set_time_seconds(&time_bits_low, &time_bits_high, seconds);
  watch_registers_set_time_minutes(&time_bits_low, &time_bits_high, minutes);
  watch_registers_set_time_hours(&time_bits_low, &time_bits_high, hours);

  uint8_t h,m,s;
  watch_registers_get_time(time_bits_low, time_bits_high, &h, &m, &s);
  TEST_ASSERT_EQUAL(hours, h);
  TEST_ASSERT_EQUAL(minutes, m);
  TEST_ASSERT_EQUAL(seconds, s);
}

//TODO: create more unit-tests.

int main (int argc, char * argv[])
{
    UnityBegin();

    MY_RUN_TEST(test_setting_time_hours);
    MY_RUN_TEST(test_setting_time);

    return UnityEnd();
}
