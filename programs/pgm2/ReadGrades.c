#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgm2.h"

// reads the file grades.txt line by line
// and assigns the names and grades to the struct 

void ReadGrades(Student_t *student, char buffer[40]) {

	char *token;
	int l = 0;
	const char c[2] = ",";
	double grade;
	char *temp;
	token = strtok(buffer, c);
	strcpy(student->First_name, token);
	while( token != NULL) {
		token = strtok(NULL, c);
		if (l == 0) {
			strcpy(student->Last_name, token);
		}

		// catches the last value of the list which is a number
		// then converts it to a int

		if(l == 1) {
			// I used this to convert the string into a double
			student->Grade = strtod(token, &temp);
		}
		l++;
	
	}


	return;
}


