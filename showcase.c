#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// the functions titled as shapes are used for calculating diferent areas, and perimeters.
void  Rectangle(double a, double b) {
	
	double area;
	double perimeter;
	area = a * b;
	perimeter = (2 * a) + (2 * b);
	printf("The area of the Rectangle is: %lf\n", area);
	printf("The perimeter of the Rectangle is : %lf\n", perimeter);
	return;
}

void  Circle(double a){
	
	double PI = 3.14;
	double Circumference;
	double area;
	Circumference = 2 * PI * a;
	area = PI * pow(a, 2);
	printf("The area of the Circle is: %lf\n", area);
	printf("The Circumference of the Circle is: %lf\n", Circumference); 
	return;
}

void Triangle(double a, double b) {
	
	double area;
	area = (a * b) / 2;
	printf("The area of the Triangle is: %lf\n", area);
	return;

}

// the next two functions are used for my standard deveation calculator.
double ave(double a, double b){
	double c;
	c = a / (double) b;
	return c;
}

double stdDev(double a, int b, int c) {

	double s, standardDev;

	s = (b - pow(a, 2)) / c;
	standardDev = sqrt(s);
	return standardDev;
}
// the following to functions are help tables for the programs below.
void options() {
	printf("---------------------------------------\n");
	printf("Type + to add\n");
	printf("Type - to subtract\n");
	printf("Type * to multiply\n");
	printf("Type / to divide\n");
	printf("Type C to clear\n");
	printf("Type S to stop using the calculator\n");
	printf("--------------------------------------\n");
	return;
}

void shapeOptions() {
	printf("------------------------------------------------\n");
	printf("Type T to calculate a triangle\n");
	printf("Type C to calculate a Circle\n");
	printf("Type R to calculate a Rectangle\n");
	printf("Type H for help\n");
	printf("Type S to stop using the shape calculator\n");
	printf("------------------------------------------------\n");
	return;
}
int main(void) {

	char choice;
	
	int i = 0;

	printf("Choose which program you want to use.\n");
	
	while (i <= 0) {
		
		// I wanted to make a multi funtional program that can do many diferent processes.
		// I felt that is was also good to get used to writing really long programs.
		printf("Type C for calculator\n");
		printf("Type S for shapes\n");
		printf("Type I for standard deveation\n");
		scanf("%c", &choice);

		switch(choice) {
			case 'C' :
				printf("running calculator\n");
				i++;
				break;
			case 'S' :
				printf("running shapes\n");
				i++;
				break;
			case 'I' :
				printf("running standard deveation\n");
				i++;
				break;
			default :
				printf("Invalid format.\n");
				printf("Try again.\n");
		}
	}

	if (choice == 'C') {
		// this is just a simple calulator.
		// I could have used more functions and added other calulations like square root and exponets. 
		// I will add that stuff another time.
		double ANS = 0;
		double new_num = 0;
		int a = 0;
		printf("Welcome to the simple calculator\n");
		printf("You can type H  for calculation inputs\n");
		while (a < 1 ) {
			char operand;
			printf("Enter a number\n");
			
			scanf("%lf", &new_num); 	
			printf("Enter an operation or type H for help.\n");
			
			scanf(" %c", &operand);
			// the switch statement helps pick the proper operation. 
			switch(operand) {
				case '+' :
					ANS += new_num;
					printf("ANS = %lf\n", ANS);
					break;
				case '-' :
					ANS -= new_num;
					printf("ANS = %lf\n", ANS);
					break;
				// for both multiplication and division.
				// I had to add if statements. 
				// with out the if statements the ANS would be zero.
				// so, if you start off by multiplying by 5 the progrram will return 5.
				case '*' :
					if (ANS == 0){
						printf("Enter in number to multiply by new number\n");
						scanf("%lf", &ANS);
					}
					ANS *= new_num;
					printf("ANS = %lf\n", ANS);
					break;
				case '/' :
					if (ANS == 0) {
						printf("ENter in the number you want to divided by the new number\n");
						scanf("%lf", &ANS);
					}
					ANS /= new_num;
					printf("ANS = %lf\n", ANS);
					break;
				case 'H' :
					options();
					break;
				case 'S' :
					printf("Tanks for using the calculator!\n");
					a++;
					break;
				case 'C' :
					ANS = 0;
					printf("%lf\n", ANS);
				       	break;	
				default :
					printf("sorry invalid input.\n");
					printf("Type H for help\n");
			
			}
		}	
	
	}
	
	else if (choice == 'S') {
		// runs the shape calculator whitch calculates the areas and perimeters of differnt shapes.
		int b =0;	
		printf("Welcome to the shape calculator\n");
		printf("The length of the Sides and radius is needed for calculations\n");
		
		while (b < 1) {
			// the user is able to pick a shape.
			// the user can input the different parameters depending on the shape.
			// and the area and perimeter will be printed to the screen.
			char shape;	
			double radius = 0;
			double sideA = 0;
			double sideB = 0;
			printf("Enter the type of shape you want to calculate\n");
			scanf(" %c", &shape);
			// I plan on adding more shapes maybe.
			switch(shape) {
				case 'C' :
					printf("Enter the radius\n");
					scanf("%lf", &radius);
					Circle(radius);
					break;
				case 'T' :
					// I want to add a lot more info for triangles.
					printf("Enter the height then base of the triangle\n");
					scanf("%lf\n %lf", &sideA, &sideB);
					Triangle(sideA, sideB);
					break;
				case 'R' :
					printf("Enter in the first sidelength then the second sidelength.\n");
					scanf("%lf\n" "%lf", &sideA, &sideB);
					Rectangle(sideA, sideB);
					break;
				case 'H' :
					shapeOptions();
					break;
				case 'S' :
					printf("Thanks for using the shape calculator\n");
					b++;
				default :
					printf("invalid input\n");
					printf("Type H for help\n");	       
			
			}
		}

		


	}

	// I want to add more to this section to make it up to the user.
	// I also plan on adding file redirection. 
	if (choice == 'I') {
		srand(time(NULL));
		int upper;
		int p = 0;
		int x[10] = {0};
		int l = 0;
		int total = 0;
		double AVE;
		int sum_sqr;
		char cont;
		// having issues with while loop.
		// I might change it to a differnt type of loop.
		// will update later.
		while ( p < 1){
			
			

			printf("Enter the upper bound for the randome numbers\n");
			scanf("%d", &upper);	
			for ( i = 0; i < 10; i++ ) {
				int num = rand() % (upper) + 1;
				total += num;
				sum_sqr = num * num;
				AVE = ave(total, 10);
				x [l] = num;
				printf("%d\n", x[l]);
				l++;
			}
			double STD;
			STD = stdDev(AVE, sum_sqr, 10);
		
			printf("The standard deveation is: %lf\n", STD);
			
		printf("Do you want to calculate more?\n");
		printf("Type Y for yes or N for no\n");
		scanf(" %c", &cont);
		if (cont == 'N' && cont == 'n'){
			
			return p = 2;
		}
		else if (cont == 'Y' && cont == 'y') {
			printf("Continuing on!\n");
		}
		
		}


	}
	return 0;



}



