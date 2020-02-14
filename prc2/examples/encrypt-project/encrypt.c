#include "encrypt.h"

void doet_iets_geheims(void)
{
	/* Doe lekker niets */
	return;
}

uint16_t geef_een_getal_terug(void)
{
	return 0xAFFE;
}

uint16_t tel_twee_getallen_op(uint16_t a, uint16_t b)
{
	return a + b;
}


uint16_t optellen_en_kwadraat(uint16_t a, uint16_t b)
{
	uint16_t som = tel_twee_getallen_op(a,b);
	return som*som;
}
