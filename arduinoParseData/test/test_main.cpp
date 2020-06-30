#include <Arduino.h>
#include <Stepper.h>
#include <string.h>
#include <unity.h>
#include "calculateStepper.h"
#include "processValues.h"

//for more info about arduino unit tests: https://docs.platformio.org/en/latest/plus/unit-testing.html#api 
Stepper stepper(STEPS, 8, 10, 9, 11);

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_split_tokens()
{
    char buffer[] = "speed@200";
    char valueType[20];
    char value[20];
    splitTokens(buffer, valueType, value);
    TEST_ASSERT_EQUAL("speed", valueType);
    TEST_ASSERT_EQUAL("200", value);
}

//physical test
void test_calculate_stepper_speed()
{
    float speed = 250;
    float stepsToMake = calculateStepsSpeedometer(speed);
    stepper.step(-stepsToMake); //if calculated correctly the pointer changes 45 degrees
    Serial.println("Type 1 in the serial monitor if succesfull or above 1 when unsuccessfull");
    while (Serial.parseInt() == 0)
    {
        if (Serial.available() > 0)
        {
            int incomingByte = Serial.read();
            TEST_ASSERT_EQUAL_INT(1, incomingByte);
        }
    }
    stepper.step(stepsToMake);
}

void test_process_value_speed()
{
    char speed[] = "250";
    char valueType[] = "speed";
    processValue(valueType, speed);
    delay(2000); //todo: if above serial input system works, implement here for if the correct dial moved
    char speed2[] = "-250";
    processValue(valueType, speed2);
}

void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    UNITY_BEGIN(); // IMPORTANT LINE!
    stepper.setSpeed(4);
    //Physical tests
    RUN_TEST(test_calculate_stepper_speed);
    RUN_TEST(test_process_value_speed);
}
void loop()
{
    UNITY_END(); // stop unit testing
}