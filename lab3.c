#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>


// this is my standard deveation function
double stdDev(double a, int b, int c) {
	double s, standardDev;

	s = (b - pow(a, 2)) / c ;
	
	standardDev = sqrt(s);
	// There is a error with this formula 
	// this is the formula from the book
	// but when the average squared is greater then the sum of the squares 
	// the value under the squar root is neg that is why it returns a -nan
	// my program is working correctly its the formula that is not working
	// if I'm wrong please tell me because I want to correct any errors


	


	return standardDev;


}
// this is my function used to find the average
double ave(double a, double b) {

	double c;

	c = a / (double) b;
	return c;
}


int main(void) {
	
	int N, upper, lower;
	

	srand( time(NULL));

	int i;
	
	// I used a for loop here so I dont have to re type everything three times
	for ( i = 0; i < 3; i++){

		printf("Enter the amount of numbers you want\n");
		scanf("%d", &N);
		printf("Enter the upper limit: \n");
		scanf("%d", &upper);
		
		printf("Enter the lower limit: \n");
		scanf("%d", &lower);
		
		// I dont like making this many integers but I got no warnings and it works
		int smallest = upper + 1;
		int largest = -1;
		int l;
		int total = 0;
		double AVE = 0;
		int sumSqr = 0;
		for (l = 0; l < N; l++) {
			int num = rand() % (upper) + 1;
			total += num;
			if (num < smallest) {
				smallest = num;
			}
			if (num > largest) {
				largest = num;
			}
			sumSqr += num * num;
			AVE = ave(total, N);
			

		}
		// I could have just printed the value of the function but I felt more 
		// confortable doing it this way
		double STD = 0;
		STD = stdDev(AVE, sumSqr, N);
		printf("The Standard Deveation is = %lf\n", STD);
		printf("The smallest number is %d\n", smallest);
		printf("the largest number is %d\n",  largest);
		// this is a math error not a programing error
		// using the formula in the book 
		// if the average squared is bigger then the sum for the squars then
		//

	}
	
}

