#include <stdio.h>
#include <math.h>

int main(void) {
	double x[20], y[20]; 
	int no_items;
	int i = 0;
	int no_elements;

	printf("Reading in each number\n");
	do {	


		no_items = scanf("%lf %lf", &x[i], &y[i]);
		i++;
	} while (no_items > 0);
	no_elements = --i;
	
	for (i = 0; i < no_elements; ++i) {
		printf("[%d] is %.2lf, y[%d] is %.2lf\n", i, x[i], i, y[i]);
	}
	
	return(0);
}
