#include <Arduino.h>
#include <Stepper.h>
#include <string.h>
#include <unity.h>
#include "showExtras.h"
#include "readSerial.h"
#include "pinOutput.h"
#include "movingAverage.h"
#include "calculateStepper.h"
Stepper stepper(STEPS, 8, 10, 9, 11);

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_calc_with_pointer()
{
    int pointerValue = 0;
    doCalcWithPointer(20, &pointerValue);
    TEST_ASSERT_EQUAL(100, pointerValue);
}

void test_fill_vehicleData()
{
    float speed = 100;
    float flyingHeight = 200;
    float fuelLeft = 243;
    fillVehicleWithData(speed, flyingHeight, fuelLeft);
    speed = 0;
    flyingHeight = 0;
    fuelLeft = 0;
    retrieveDataFromVehicle(&speed, &flyingHeight, &fuelLeft);
    TEST_ASSERT_EQUAL(100, speed);
    TEST_ASSERT_EQUAL(200, flyingHeight);
    TEST_ASSERT_EQUAL(243, fuelLeft);
}

void test_moving_average()
{
    float value1 = 0;
    for (int i = 1; i <= 10; i++)
    {
        float value = calcMovingAverage(i);
        if (value != -1)
        {
            value1 = value;
        }
    }
    TEST_ASSERT_EQUAL_FLOAT(5.5f, value1);
}

void test_custom_pin_13()
{
    //test with direct function
    int pin = 13;
    setPinMode13(true);
    digitalWrite(pin, HIGH); // fysiek kijken of het lampje brand
    TEST_ASSERT_EQUAL(HIGH, digitalRead(13));
    delay(2000);
    setPinMode13(false); //fysiek kijken of het lampje niet meer brand.
    delay(2000);
    //test with mask
    customPinModeHigh(0b00100000); // fysiek kijken of het lampje weer brand
    delay(2000);
    customPinModeHigh(0); // fysiek kijken of het lampje uit is
    delay(1000);
    digitalWrite(pin, LOW); // fysiek kijken of het lampje brand
}

void test_calculate_stepper()
{
    char arraytje[] = "250";
    float stepsToMake = calculateStepsSpeedometer(arraytje);
    stepper.step(-stepsToMake); //if calculated correctly the pointer changes 45 degrees
    delay(2000);
    stepper.step(stepsToMake);
}

void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    UNITY_BEGIN(); // IMPORTANT LINE!
    RUN_TEST(test_calc_with_pointer);
    RUN_TEST(test_fill_vehicleData);
    RUN_TEST(test_moving_average);
    stepper.setSpeed(4);
    RUN_TEST(test_calculate_stepper);
    //fysieke test:
    RUN_TEST(test_custom_pin_13);
}
void loop()
{
    UNITY_END(); // stop unit testing
}