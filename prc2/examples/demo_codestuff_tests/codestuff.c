#include "codestuff.h"
#include <stddef.h>

uint16_t geef_een_getal_terug(void)
{
	return 0xAFFE;
}

int tel_twee_getallen_op(uint16_t a, uint16_t b, uint16_t *sum)
{
	*sum = a + b;
	return 0;
}

uint16_t optellen_en_kwadraat(uint16_t a, uint16_t b)
{
	uint16_t som = 0;
	//tel_twee_getallen_op(a,b, &som);
	return som*som;
}

int voegGetalToe(int *getallenArray,
                 int maximumLengteGetallenArray,
                 int aantalElementenInArray,
                 int toeTeVoegenGetal,
                 int *nieuwAantalElementenInArray)
{
	if(getallenArray == NULL) return -1;
	if(nieuwAantalElementenInArray == NULL) return -1;

	//if(...) return -1;

	getallenArray[aantalElementenInArray] = toeTeVoegenGetal;
	*nieuwAantalElementenInArray += 1; //aantalElementenInArray + 1;

	return 0;
}
