#include <string.h>

#include "dispatcher2.h"
#include "unity.h"
#include "resource_detector.h"

// TODO: interface van addAnimal aanpassen (lastig te begrijpen voor meerdere studenten, nu geen leerdoel)

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

#define OK (0)
#define NOK (-1)



void setUp(void) { // This is run before EACH test
    initdispatcher();
}

void tearDown(void) { // This is run after EACH test
}
// we need at least two test, which are given here.
// Implement these and more to test complete functionality
// the current tests will run AND pass but actually they do not do anything

// the following tests if the dispatcher is correctly initialized
void test_initialization() {

	TEST_ASSERT( true==false);
}
// the following tests the correct functioning of the dispatcher
// Think about an algoritm which can be used to do this.
void testdispatcher()
{

}

int main (int argc, char * argv[]) {
   UnityBegin();

	 MY_RUN_TEST(test_initialization);
	 MY_RUN_TEST(testdispatcher);

	 return UnityEnd();
}
