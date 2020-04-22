#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pgm2.h"

// this function takes each student and LetterGrade and puts them together in one string 
// I didnt want to use so many if statments but I had no choice since for some reason
// I could not have a Letter and a '-' or '+' sign in the same string and return it. 


int PrintGrade(Node_t** head, char curved, char *LetterGrade, FILE *file_out) {
	Node_t* cur = *head;


	// I used two strings to get the data to print correctly.
	char Grade[2];
	char s[1];
	
	if (LetterGrade[0] == 'a'){
		strcat(Grade, "A");
		s[0] = '-';	
	}
	if(LetterGrade[0] == 'V'){
		strcat(Grade, "B");
		s[0] = '+';
	}
	if(LetterGrade[0] == 'b') {
		strcat(Grade, "B");
		s[0] = '-';
	}
	if(LetterGrade[0] == 'X') {
		strcat(Grade, "C");
		s[0] = '+';
	}
	if(LetterGrade[0] == 'c'){
		strcat(Grade, "C");
		s[0] = '-';
	}
	if(LetterGrade[0] == 'S') {
		strcat(Grade, "D");
		s[0] = '+';
	}
	if(LetterGrade[0] == 'd') {
		strcat(Grade, "D");
		s[0] = '-';
	}
	if(LetterGrade[0] == 'A'){
		strcat(Grade, "A");
		
	}
	if(LetterGrade[0] == 'B') {
		strcat(Grade, "B");
		
	}
	if(LetterGrade[0] == 'C') {
		strcat(Grade, "C");
	}
	if(LetterGrade[0] == 'D') {
		strcat(Grade, "D");
	}



	fprintf(file_out,"Name: %s %s Grade: %lf %s%c Cruved? %c\n",
			cur->c112->First_name, cur->c112->Last_name, cur->c112->Grade,
		       	Grade,  s[0], curved);
	
	Grade[0] = '\0';
	s[0] = '\0';
	return 0;
}


