#include <stdio.h>
#include <stdlib.h>



int main(void) {
	
	FILE *file_in = fopen("doubles.txt", "r");
	FILE *file_out = fopen("Out_file.bin", "wb");	
	if (file_in == NULL) {
		printf("Error!, File does not exist");
		exit(1);
	}

	int bufferLength = 60;
	char buffer[bufferLength];
	
	double Array[20];
	int i = 0;
	while(fgets(buffer, bufferLength, file_in)) {
		double num = strtod(buffer, NULL);

		Array[i] = num;
		++i;	
	}
	
	fwrite(Array, 1, sizeof(Array), file_out);
	
	double sum;
	for (int l = 0; l < i; l++) {
		sum += Array[l];
	}
	printf("Sum = %lf\n",sum);

}
