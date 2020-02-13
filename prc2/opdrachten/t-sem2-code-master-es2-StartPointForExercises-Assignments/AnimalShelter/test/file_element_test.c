#include <string.h>

#include "file_element.h"
#include "unity.h"
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
}

void test_EmptyTest(void)
{
    TEST_ASSERT_EQUAL(1, 0);
}

int main (int argc, char * argv[])
{
    UnityBegin();

    MY_RUN_TEST(test_EmptyTest);

    return UnityEnd();
}
