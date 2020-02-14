#include "decrypt.h"
#include "unity.h"
#include <stdio.h>

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

/*
void setUp(void)
{
    printf("This is run before EACH test.\n");
}

void tearDown(void)
{
    printf("This is run after EACH test.\n");
}
*/

void test_decrypt_test1() {
  uint8_t a = 40, b = 0;

  decrypt_example(a, &b);
  TEST_ASSERT_EQUAL(a,b);
}

void decrypt_run_tests()
{
    MY_RUN_TEST(test_decrypt_test1);
}
