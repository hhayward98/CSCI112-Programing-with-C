#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgm2.h"
#include <math.h>

void SortedInsert(Node_t**, Node_t**);


void ReadGrades(Student_t *student, char buffer[40]) {

	char *token;
	int l = 0;
	const char c[2] = ",";
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


void ListInsert(Node_t** head, Student_t* st) {

	Node_t* new_node = malloc(sizeof(Node_t));
	new_node->st = st;
	new_node->next = NULL;

	Node_t* old_head = *head;
	*head = new_node;
	new_node->next = old_head;

	return;
}

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
			cur->st->First_name, cur->st->Last_name, cur->st->Grade,
		       	Grade,  s[0], curved);
	
	Grade[0] = '\0';
	s[0] = '\0';
	return 0;
}




void sort(Node_t** head) {
	Node_t* sorted = NULL;// sorted list.


	Node_t* cur = *head;

	while (cur != NULL) {
		
		Node_t* next = cur->next;
		SortedInsert(&sorted, &cur);

		cur = next;
	}
	*head = sorted;
	return;
}


void SortedInsert(Node_t** head, Node_t** new_node) {

	Node_t* cur;
	Node_t* test_node;
	test_node = *new_node;
	
	if (*head == NULL || (*head)->st->Grade < test_node->st->Grade) {

		test_node->next = *head;
		*head = test_node;
	}
	else {
		cur = *head;
		while (cur->next != NULL && cur->next->st->Grade > test_node->st->Grade) {
			cur = cur->next;
		}

		test_node->next = cur->next;
		cur->next = test_node;
	}
	return;
}



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

	Student_t c112;

	while(fgets(buffer, bufferLength, file_in)) {
	
		Student_t* st = malloc(sizeof(Student_t));
		ReadGrades(st, buffer);
		
		ListInsert(&LL_head, st);


	}
	sort(&LL_head);
	Node_t* cur = LL_head;
	while (cur != NULL) {
		double Temp = cur->st->Grade;
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

