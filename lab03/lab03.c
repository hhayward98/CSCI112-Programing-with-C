#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



int main () {
	

	int i, n;
	time_t t;
	int a, b, c;

	srand(time(NULL));

	n = 5;
	printf("enter the number of elements you want");

	scanf("%d\n", &a);

	for ( i = 0 ; i < a ; i++ ) {
		printf("%d\n", rand() % 20);
	}

	return(0);
}

