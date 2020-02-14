#include "codestuff.h"
#include "unity.h"
#include <stdio.h>

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{
    //printf("This is run before EACH test.\n");
}

void tearDown(void)
{
    //printf("This is run after EACH test.\n");
}

void test_geef_een_getal_terug() {
	TEST_ASSERT_EQUAL(0xAFFE, geef_een_getal_terug());
}

void test_tel_twee_getallen_op(void)
{
	uint16_t sum = 0;
	int return_code = tel_twee_getallen_op(4,2, &sum);

	TEST_ASSERT_EQUAL(0, return_code);

  TEST_ASSERT_EQUAL(6, sum);
}

void test_optellen_en_kwadraat(void)
{
	TEST_ASSERT_EQUAL( 49 , optellen_en_kwadraat(3,4));
}

void test_voeg_getal_toe_aan_leeg_array(void)
{
	int array[] = {1,2,8,0};
	int maximumLengteGetallenArray = 4;
	int aantalElementenInArray = 0;
	int toeTeVoegenGetal = 42;
	int nieuwAantalElementenInArray = 0;

	int result = voegGetalToe(array, maximumLengteGetallenArray, aantalElementenInArray,
							 toeTeVoegenGetal, &nieuwAantalElementenInArray);

  TEST_ASSERT_EQUAL(0, result);
	TEST_ASSERT_EQUAL(toeTeVoegenGetal, array[0]);
	TEST_ASSERT_EQUAL(1, nieuwAantalElementenInArray);
}

void test_voeg_getal_toe_aan_gedeeltelijk_vol_array(void)
{
	int array[] = {1,2,8,10};
	int maximumLengteGetallenArray = 4;
	int aantalElementenInArray = 2;
	int toeTeVoegenGetal = 44;
	int nieuwAantalElementenInArray = 0;

	int result = voegGetalToe(array, maximumLengteGetallenArray, aantalElementenInArray,
							 toeTeVoegenGetal, &nieuwAantalElementenInArray);

  TEST_ASSERT_EQUAL(0, result);

	TEST_ASSERT_EQUAL(1, array[0]);
	TEST_ASSERT_EQUAL(2, array[1]);
	TEST_ASSERT_EQUAL(toeTeVoegenGetal, array[2]);
	TEST_ASSERT_EQUAL(10, array[3]);

	TEST_ASSERT_EQUAL(3, aantalElementenInArray);
}

void test_voeg_getal_toe_aan_vol_array(void)
{
	int array[] = {1,2,8,0};
	int maximumLengteGetallenArray = 4;
	int aantalElementenInArray = 0;
	int toeTeVoegenGetal = 42;
	int nieuwAantalElementenInArray = 0;

	int result = voegGetalToe(array, maximumLengteGetallenArray, aantalElementenInArray,
							 toeTeVoegenGetal, &nieuwAantalElementenInArray);

  TEST_ASSERT_EQUAL(0, result);
	TEST_ASSERT_EQUAL(42, array[0]);
	TEST_ASSERT_EQUAL(1, nieuwAantalElementenInArray);
}

void test_voeg_getal_toe_met_NULLEN_als_input(void)
{
	int array[4];
	int maximumLengteGetallenArray = 4;
	int aantalElementenInArray = 0;
	int toeTeVoegenGetal = 42;
	//int *nieuwAantalElementenInArray = NULL;

	int result = voegGetalToe(NULL, maximumLengteGetallenArray, aantalElementenInArray,
							 toeTeVoegenGetal, &aantalElementenInArray);

  TEST_ASSERT_EQUAL(-1, result);

	result = voegGetalToe(array, maximumLengteGetallenArray, aantalElementenInArray,
							 toeTeVoegenGetal, NULL);

  TEST_ASSERT_EQUAL(-1, result);

}

int main (int argc, char * argv[])
{
    UnityBegin();

    MY_RUN_TEST(test_geef_een_getal_terug);
    MY_RUN_TEST(test_tel_twee_getallen_op);
		MY_RUN_TEST(test_optellen_en_kwadraat);

		MY_RUN_TEST(test_voeg_getal_toe_aan_leeg_array);
		MY_RUN_TEST(test_voeg_getal_toe_aan_gedeeltelijk_vol_array);
		MY_RUN_TEST(test_voeg_getal_toe_met_NULLEN_als_input);
	  
    return UnityEnd();
}
