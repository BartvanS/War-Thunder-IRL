#include "unity.h"
#include <stdio.h>
#include <stdint.h>

extern void encrypt_run_tests();
extern void decrypt_run_tests();

void setUp(void)
{
    //printf("This is run before EACH test.\n");
}

void tearDown(void)
{
    //printf("This is run after EACH test.\n");
}

int main (int argc, char * argv[])
{
    UnityBegin();

    encrypt_run_tests();
    decrypt_run_tests();

    return UnityEnd();
}
