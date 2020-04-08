#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgm1.h"
#include <math.h>

// this main takes in the file grades.txt and sends its contents to other functions to 
// figure out all the requiered information.

int main(void) {

	FILE *file_in;
	FILE *file_out;
	file_in = fopen("grades.txt", "r");
	
	if (file_in == NULL) {
		printf("Error! no such file");
		exit(1);
	}

	file_out = fopen("Grades_final.txt", "w");

	int bufferLength = 60;
	char buffer[bufferLength];
	char grade[20];
	char curve;

	Student_t c112;

	while(fgets(buffer, bufferLength, file_in)) {

		ReadGrades(&c112, buffer);
		// this is how I determined if the grade was curved.
		if ( c112.Grade < round(c112.Grade )){
				curve = 'Y';
		}
		else {
			curve = 'n';
		}

		*grade = CalculateLetterGrade(c112.Grade);
		
		PrintGrade(c112, curve, grade, file_out); 
	}

	fclose(file_in);
	fclose(file_out);
	return 0;
}
				
