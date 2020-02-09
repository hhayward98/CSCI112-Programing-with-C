#include <stdio.h>
#include <stdlib.h>


int main() {


	double t, d, x = 0;
	char a;

	printf("Enter the cost of your items: ");
	scanf("%lf", &t);
	printf("%lf", &t);
	 
	printf("Are you a music teacher");
	
	scanf(" %c", &a);
	if ((a = 'y') && (a = 'Y') ) {
		if (t > 100) {
			printf("%lf\n", &t);
                        d = t * .12;
	
	 	}

		printf("%lf", &d);
	}


	return(0);
}
