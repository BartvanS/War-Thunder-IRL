#include <string.h>

#include "timer2.h" // or timer1.h for the first run
#include "unity.h"
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)
#define OK (0)
#define NOK (-1)


// the current tests will run AND pass but actually they do not do anything
// add your own tests here

void setUp(void) { // This is run before EACH test

}

void tearDown(void) { // This is run after EACH test
}

void test_test() {

	TEST_ASSERT_EQUAL(true, true);
}

int main (int argc, char * argv[]) {
	UnityBegin();

	MY_RUN_TEST(test_test);

	return UnityEnd();

}
