#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	FILE* file = fopen("x_y_polygon.txt", "r");
	char line[256];
	double x, y;
	int num;
	do {
		num = fscanf(file, "%lf  %lf\n", &x, &y);
		printf("  %lf  %lf\n", x, y);
	}while( num != 0);
	fclose(file);
	return 0;



}
