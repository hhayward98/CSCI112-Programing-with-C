#include <stdio.h>
#include "pgm1.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

double Readgrades(Student_t student, char buffer[40]) {
	char *token;
	int l = 0;
	const char c[2] = ",";
	

	token = strtok(buffer, c);
	strcpy(student.First_name, token);
	while(token != NULL) {
		token = strtok(NULL, c);
		if (l == 0) {
		strcpy(student.Last_name, token);
		}
	// catches the last value of this list which is a number and converts 
	// the str into a int then puts it inside of an int array	
		if(l == 1) {		
			student.Grade = atoi(token);
				
		}
		l++;
				
	}

	printf("Name: %s %s Grade: %lf\n",
	student.First_name, student.Last_name, student.Grade);

	return student.Grade;

}

char CalculateLetterGrade(int grade) {
	char Letter[2];
	char temp[2];


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
	printf(" grade is : %s\n", Letter);
	
	return *Letter;
}

// reads in all the students and Thier Letter grades

int Printgrade(Student_t student, char buffer[40]) {
	char *token;
	int l = 0;
	const char c[2] = ",";
	char curved[3];	

	token = strtok(buffer, c);
	strcpy(student.First_name, token);
	while(token != NULL) {
		token = strtok(NULL, c);
		if (l == 0) {
		strcpy(student.Last_name, token);
		}
		if(l == 1) {		
			student.Grade = atoi(token);
				
		}
		l++;
				
	}
	if (student.Grade < round(student.Grade)) {
		strcat(curved,"Yes");
	}
	else {
		strcat(curved, "No");
	}	
//	printf("Name: %s %s Grade: %lf %c Curved? %c\n",
	printf("Name %s %s Grade: %lf %c\n",
	student.First_name, student.Last_name, student.Grade, *curved);	
	return 0;
}


int main(void) {
	
	FILE *file_in;
	FILE *file_out;

	file_in = fopen("grades.txt", "r");

	if (file_in == NULL) {
		printf("Error! no such file");
		exit(1);
	}
	
	file_out = fopen("grades_final.txt", "w");		

	int i, j, k, l; //counter
	int bufferLength = 60;
	char buffer[bufferLength];
	char Grade[20];
	double intP;
	char temp[2];
	

	Student_t c112[30];
	
	k = 0;
	i = 0;
	l = 0;
	// reads in the file line by line
	while(fgets(buffer, bufferLength, file_in)) {
					
		intP = Readgrades(c112[i], buffer);
	
	//	printf("%lf\n", round(intP));
		*Grade = CalculateLetterGrade(intP);

		strcpy(temp, Grade);
		
		printf("%s\n", temp);
//		Printgrade(c112[i], buffer);
		i++;
		temp[0] = '\0';



		// adds all the students to c112
		
		
	}
	// prints everything to the output file

	//for (j = 0; j < k; j++) {

	//}
	//use wile statment.
	// reads in each student and assigns thier information to the struct.
	
	// send the struct to Readgrades to return the grades
	

	// sends the grades to the CalculateLettergrade
	// to return the letter grade
	

	// sends all the information to Print letter grade which will print everything to the 
	// output file. 
		
	fclose(file_in);
	fclose(file_out);
	return 0;

}


