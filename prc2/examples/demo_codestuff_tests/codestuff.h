#ifndef CODESTUFF_H
#define CODESTUFF_H

#include <stdint.h>

uint16_t geef_een_getal_terug(void);

/*
*  @param
 * @returns 0 on succes, 1 on failure
 */
int tel_twee_getallen_op(uint16_t a, uint16_t b, uint16_t *sum);

uint16_t optellen_en_kwadraat(uint16_t a, uint16_t b);

int voegGetalToe(int *getallenArray,
                 int maximumLengteGetallenArray,
                 int aantalElementenInArray,
                 int toeTeVoegenGetal,
                 int *nieuwAantalElementenInArray);

#endif
