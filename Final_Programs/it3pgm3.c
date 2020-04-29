#include <stdio.h>
#include <stdlib.h>



int main(void) {
	
	FILE *file_in = fopen("doubles.txt", "r");
	
	if (file_in == NULL) {
		printf("Error!, File does not exist");
		exit(1);
	}

	int bufferLength = 60;
	char buffer[bufferLength];

	while(fgets(buffer, bufferLength, file_in)) {
		printf("%s\n", buffer);
	}


}
