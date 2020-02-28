#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	FILE* file = fopen("x_y_polygon.txt", "r");
	char line[256];
	int i = 0;
	while (fgets(line, sizeof(line), file)) {
		i++;
		if(i == 9)
			printf("%s", line);
	}
	fclose(file);

	return 0;



}
