#include <stdio.h>


int main() {
	

	char a = '\0';

	printf("hello");
	scanf(" %c", &a);

	if (a == 'y'|| a == 'Y')
		printf("yes");
	
	if (a == 'n')
		printf("no");
}
