#include <stdio.h>
#include <stdint.h>

void maakPincode(char* kamerPincode12,
								 char* kamerPincode34,
							 	 int* kamerPincodeResultaat)
{
		*kamerPincodeResultaat = (*kamerPincode34) + (*kamerPincode12) * 100;
}


int main (int argc, char * argv[])
{
	int res = 42;
	int *wijzerNaarRes = NULL;

	wijzerNaarRes = &res;

	printf("res: \t\t waarde = %d; adres = %p\n", res, (void*)&res);

	printf("wijzerNaarRes: \t waarde = %p; adres = %p\n", (void*)wijzerNaarRes, (void*)&wijzerNaarRes);

	printf("wijzerNaarRes: \t value op adres: %d\n\n", *wijzerNaarRes);

	int anotherRes = 84;
	wijzerNaarRes = &anotherRes;

	printf("anotherRes: \t waarde = %d; address = %p\n\n", anotherRes, (void*)&anotherRes);
	printf("wijzerNaarRes: \t waarde = %p; address = %p\n", (void*)wijzerNaarRes, (void*)&wijzerNaarRes);

	printf("wijzerNaarRes: \t value op address: %d\n\n", *wijzerNaarRes);

	char piCode12 = 99;
	char piCode34 = 11;
	int piCode;

	maakPincode(&piCode12, &piCode34, &piCode);

	printf("Pincode = %d\n", piCode);

	return 0;
}
