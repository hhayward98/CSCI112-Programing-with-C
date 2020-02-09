#include <stdio.h>
#include <stdlib.h>



int main() {

	double  d, t, x;
	int i = 0;	

	for ( i = 0; i < 3; i++ ) {
		
	
		printf("Enter the cost of your items: ");
		scanf("%lf", &t);

		printf("Are you a music teacher: ");
		char a = '\0';
	
		scanf(" %c", &a);
		if ((a == 'y') || (a == 'Y') ) {

			if (t > 100) {
				
				printf("Total purchases                   %.2lf $ \n", t);
				d = t * .12;
				printf("Teacher's dicount (12%%)           %.2lf\n", d);
			

				d = t - d;
				printf("Discounted total                  %.2lf $ \n", d);
				x = d * .05;
		                printf("Sales tax (5%%)                    %.2lf\n", x);
               			x = d + x;

               			printf("Total                             %.2lf $ \n", x);



			}
			else {
				printf("Total purchases                     %.2lf $ \n", t);
				d = t * .1;
				printf("Teacher's discount (10%%)            %.2lf\n", d);
				d = t - d;
				printf("Discount total                      %.2lf $ \n", t);
				
				x = d * .05;
                		printf("Sales tax (5%%)                      %.2lf\n", x);
                		x = d + x;

                		printf("Total                               %.2lf $ \n", x);



			}

		}
		else if ((a == 'n') || (a == 'N')) {
			printf("Total purchases          %.2lf $ \n", t);
			d = t;
		

			x = d * .05;
			printf("Sales tax (5%%)           %.2lf\n", x);
			x = d + x;

			printf("Total                    %.2lf $ \n", x);
		}
		

	}
	return(0);

}

