#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// add Linked List

int main(void) {

	FILE *file_in = fopen("numbers.txt", "r");

	if (file_in == NULL) {
		printf("Error! File does not exist");
		exit(1);
	}


	int bufferLength = 60;
	char buffer[bufferLength];

	while(fgets(buffer, bufferLength, file_in)) {
		printf("%s\n", buffer);
	}

	
}
