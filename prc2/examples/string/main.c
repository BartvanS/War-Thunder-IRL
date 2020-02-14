#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
		char myName[] = "Inspector Gadget";

		printf("Name = %s -> size = %d - %d\n", myName, (int)strlen(myName), (int)sizeof(myName));

		int index = 0;
		while(true) {
			char current_char = myName[index];

			if(current_char == '\0') break;

			printf("%c\n", current_char);

			index++;
		}


		char otherName[] = "Inspector";

		printf("Compare %d\n", strcmp(myName, otherName));
		printf("Compare %d\n", strncmp(myName, otherName,9));

		myName[9] = '\0';
		printf("Name = %s -> size = %d\n", myName,(int)strlen(myName));
		printf("Compare %d\n", strcmp(myName, otherName));

		char s[] = "hello";
		char* t = "world";


		while(true) {
			if(true)
			{
				int *ptr = NULL;
				int a = 0;
				ptr = (int*)malloc(100000000);
				a = 10;
			}

		}

		s[1] = 'b';

		printf("%s %s\n", s, t);

		return 0;
}
