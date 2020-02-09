#include <stdio.h>
#include <stdlib.h>

// I wasnt sure if I had to make a function so I didnt because I felt like I didnt need to.

int main() {

	double  d, t, x;
	int i = 0;	// I set the i = 0 because I was getting warnings.

	for ( i = 0; i < 3; i++ ) {
		
	
		printf("Enter the cost of your items: ");
		scanf("%lf", &t);

		printf("Are you a music teacher: ");
		char a = '\0'; // I decleared the char here because I was getting issues.
	
		scanf(" %c", &a);
		// I didnt want to retype everything 3 times so I uesd a for loop.
		if ((a == 'y') || (a == 'Y') ) {

			if (t > 100) {
				// this cacluates the discount at 12%.
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
				//caculates the discount at 10%.
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
			// caculates with no dicount.
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

