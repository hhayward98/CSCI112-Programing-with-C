#include <stdio.h>


int main() {

	char grade;
		
	printf("Enter your grade: ");
	scanf(" %c", &grade);
	
	switch(grade) {
		case 'A':
			printf("Excellent!\n" );
			break;
		case 'B':
			printf("Good job\n" );
			break;
		case 'C':
			printf("Well done\n" );
			break;
		case 'D':
			printf("you passed\n" );
			break;
		case 'F':
			printf("You faild\n" );
			break;
		default :
			printf("invalid input");
	}
	
	printf("Your grade is %c\n", grade );
	

	int a = 10;

	do {
		printf("value of a: %d\n", a);
		a = a + 1;
	}while( a < 20 );

	return(0);


}

