#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pgm1.h"


// this function takes each grade and determins what LetterGrade to assign to that number
// I for some reason was unable to return a Letter and a '-' or '+' sign
// so I gave the values A-, B-, C-, D- all lowercase letters
// for B+, C+, D+, I assigned random uppercase Letters 
char CalculateLetterGrade(double grade) {
	char Letter[2];

	if( grade >= 93){
		strcat(Letter, "A");
	}
	if( grade < 93 && grade >= 90){
		
		strcat(Letter, "a");
	}
	if ( grade < 90 && grade >= 87) {
		
		strcat(Letter, "V");
	}
	if ( grade < 87 && grade >= 83) {
		
		strcat(Letter, "B");
	}
	if ( grade < 83 && grade >= 80) {
		
		strcat(Letter, "b");
	}
	if ( grade < 80 && grade >= 77) {
		
		strcat(Letter, "X");
	}
	if ( grade < 77 && grade >= 73) {
		
		strcat(Letter, "C");
	}
	if ( grade < 73 && grade >= 70) {
		
		strcat(Letter, "c");
	}
	if ( grade < 70 && grade >= 67) {
		
		strcat(Letter, "S");
	}
	if ( grade < 67 && grade >= 63) {
		
		strcat(Letter, "D");
	}
	if ( grade < 63 ) {
		strcat(Letter, "d");
	}
	
	return *Letter;
}
