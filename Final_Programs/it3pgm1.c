#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// data struct
typedef struct {


	char Name[40];  // name of business
	
	char Number[10];

	int Area_code;

} BCard_t;
int ReadInfo(BCard_t*);




//reads in the info to the struct
int ReadInfo(BCard_t* card) {
	
	FILE *file_in = fopen("phone_numbers.txt", "r");
	
	if (file_in == NULL) {
		printf("Error! File does not exist");
		exit(1);
	}

	int bufferLength = 60;
	char buffer[bufferLength];

	char *token;
	const char d[2] = "-";
	int i = 0;
	while (fgets(buffer, bufferLength, file_in)) {
	
		token = strtok(buffer, " ");
		strcpy(card[i].Name, token);
		token = strtok(NULL, d);
		card[i].Area_code = atoi(token);
		token = strtok(NULL, " ");
		strcpy(card[i].Number, token);
		++i;
	}
	
	fclose(file_in);
	return i;
}


int main(void) {
	
	BCard_t BC[20];
	// counts the number of peoples information recived.
	int num = ReadInfo(BC);

	int l;
	for (l = 0; l < num; l++) {
		printf("Business: %s Area code: %d  Phone: %s\n",
				BC[l].Name, BC[l].Area_code, BC[l].Number);
	}




}
