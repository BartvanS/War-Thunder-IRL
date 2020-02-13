#include "encrypt.h"
#include "unity.h"
#include <stdio.h>

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void test_geef_een_getal_terug() {
	TEST_ASSERT_EQUAL(0xAFFE, geef_een_getal_terug());
}

void test_tel_twee_getallen_op(void)
{
	TEST_ASSERT_EQUAL(6, tel_twee_getallen_op(4,2));
}

void test_optellen_en_kwadraat(void)
{
	TEST_ASSERT_EQUAL( 49 , optellen_en_kwadraat(3,4));
}

void encrypt_run_tests()
{
    MY_RUN_TEST(test_geef_een_getal_terug);
    MY_RUN_TEST(test_tel_twee_getallen_op);
	  MY_RUN_TEST(test_optellen_en_kwadraat);
}
