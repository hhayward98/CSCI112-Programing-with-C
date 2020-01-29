#include <stdio.h>
#include <math.h>


int main (void) {
	
	double hours, mins;
	double time, temp ;
	

	printf("Enter time since power faliure in hours and minutes: ");
	


	scanf("%lf", &hours);
	scanf("%lf", &mins);

	time = hours + (mins/60);
	
	temp = ((4 * pow(time, 2))/(time +2))-20;

	printf("Temperature after power failure for%.2lf", temp);
	printf("C\n");	


	return(0);
}

	
