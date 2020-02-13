/* 
 * auteur : Freddy Hurkmans
 * datum  : November 15th 2015
 * code   : C99
 */

#include "buffer.h"
#include "unity.h"

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

void test_to_see_if_our_compiler_can_add_2_integers(void)
{
    int result = 2;
    TEST_ASSERT_EQUAL(result, 1+1);
}

void test_if_buffer8_value_can_be_added_and_read(void) {
	uint8_t value = 32;
	uint32_t index = 0;
	int result = writeBufferValueAsUint8(index, value);
	TEST_ASSERT_EQUAL(0, result);
	
	uint8_t readValue = 0;
	result = readBufferValueAsUint8(index, &readValue);
	TEST_ASSERT_EQUAL(0, result);
	TEST_ASSERT_EQUAL(value, readValue);
}

int main (int argc, char * argv[])
{
    UnityBegin();
    
    MY_RUN_TEST(test_to_see_if_our_compiler_can_add_2_integers);
    MY_RUN_TEST(test_if_buffer8_value_can_be_added_and_read);
    
    return UnityEnd();
}
