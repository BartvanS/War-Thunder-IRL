/* auteur : F.J. Hurkmans
 * datum  : November 4th 2013
 * code   : Ansi C
 * versie : 1
 */

#include "stringcalc.h"
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

void firstTest(void)
{
    int result = 2;
    TEST_ASSERT_EQUAL(result, 1+1);
}

int main (int argc, char * argv[])
{
    UnityBegin();
    
    MY_RUN_TEST(firstTest);
    
    return UnityEnd();
}
