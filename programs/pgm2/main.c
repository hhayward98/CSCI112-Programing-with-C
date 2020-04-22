#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgm2.h"
#include <math.h>

int main(void) {


	Node_t* LL_head = NULL;
	
	FILE* file_in = fopen("grades.txt", "r");

	if (file_in == NULL) {
		printf("Error! no such file");
		exit(1);
	}

	FILE *file_out = fopen("Grades_file.txt", "w");

	int bufferLength = 60;
	char buffer[bufferLength];
	char grade[20];
	char curve;
//	Student_t* c112 = malloc(sizeof(Student_t));


	while(fgets(buffer, bufferLength, file_in)) {
	
		Student_t* c112 = malloc(sizeof(Student_t));
		ReadGrades(c112, buffer);
		
		ListInsert(&LL_head, c112);


	}
	sort(&LL_head);
	Node_t* cur = LL_head;
	while (cur != NULL) {
		double Temp = cur->c112->Grade;
		if (Temp < round(Temp)) {
			curve = 'Y';
		}
		else {
			curve = 'N';
		}

		*grade = CalculateLetterGrade(Temp);
		

		PrintGrade(&cur, curve, grade, file_out);
		cur = cur->next;
	}


	return 0;
}


