#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
	int i, n;
	time_t t;
	int a, b, c;


	n = 5;
	printf("enter the number of elements you want");

	scanf("%d\n", &a);

	srand((unsigned) time(&t));


	for ( i = 0 ; i < a ; i++ ) {
		printf("%d\n", rand() % 20);
	}

	return(0);
}

