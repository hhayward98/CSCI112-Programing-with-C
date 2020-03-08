#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// this function checks to see if the band color entered by the user 
// is an actual band color.
int search(char** colors, int size, char* s_color) {

	for (int i = 0; i < size; i++) {
		if (strcmp(colors[i], s_color) == 0){
			return (0);
		}
	}
	return -1;

	// takes the string and compars them to others string then uses the index to assign its number 
}

// this function computes the Rvalue for ohms.
double coumputeRvalue(int num[]) {
	int num_band1 = num[0], num_band2 = num[1], num_band3 = num[2];
	double rvalue;

	rvalue = ((num_band1 * 10) + num_band2) * pow(10.0, num_band3);

	rvalue /= 1000.0;

	return rvalue;
}


int main(void){
	// array of the possible band colors on a resistor.
	char *COLOR_CODES[] = {"black", "brown","red","orange", "yellow", "green", "blue",
		"violet", "grey", "white"};
	
	
	double ohms = 0;
	int errorHolder = 0;
	char choice = 'A';
	int i = 0;
	int L = 0;
	printf("Enter the colors of the resistor's 3 bands, beginning with\n");
	printf("the band nearest the end. Type the colors n lowercase letters only!\n");
	
	while(L < 1){
		do {

			int bandsnum[] = {0,0,0};
			char band1, band2, band3;
		
			//ask the use for the band colors then test to see if it exist.
			//then the program compairs strings to find the index of the band from COLOR_CODES
			//then adds it to the int array
			printf("Band 1 => ");
			scanf(" %s", &band1);
		
			if ((search(COLOR_CODES, 10, &band1) != 0)) {
				printf("Invalid input: %s\n", &band1);
				break;
			}
			for (int k = 0; k < 10; k++) {
	
				if (strcmp(COLOR_CODES[k], &band1) == 0) {
					bandsnum[0] = k;
					//printf("Test20 %d\n", bandsnum[0]);
				}
			}
			// for some unknown reson to me the first element in my int array 
			// would be initally set to the correct value 
			// but then would change as I did other things in my code 
			// so I added this place holder to keep the value safe
			// printf("Test21 %d\n", bandsnum[0]);
			errorHolder = bandsnum[0];
			printf("Band 2 => ");
			scanf(" %s", &band2);	
		

			if ((search(COLOR_CODES, 10, &band2) != 0 )) {
				printf("Invalid input: %s\n", &band2);
				break;
			}
			for (int k = 0; k < 10; k++) {
				if (strcmp(COLOR_CODES[k], &band2) == 0) {
					bandsnum[1] = k;
				}
			}

			//printf("Test22 %d\n", bandsnum[0]);

			printf("Band 3 => ");
			scanf(" %s", &band3);
		
			if ((search(COLOR_CODES, 10, &band3) != 0 )) {
				printf("Invalid input: %s\n", &band3);
				break;
			}
	
			for (int k = 0; k < 10; k++) {
				if (strcmp(COLOR_CODES[k], &band3) == 0) {
					bandsnum[2] = k;
				}
			
			}
			
			// I reset the value to the inital value found by my program.
			// its only the first element in the array that is affected.
			bandsnum[0] = errorHolder;	
		
			// sends the int array to the Rvalue function to get the amount of ohms
			ohms = coumputeRvalue(&bandsnum[0]);


			printf("Resistance value: %.2lf kilo-ohm\n", ohms);
			
			i++;

		}while(i < 1);
		
		int j = 0;

		do {


			// I had to use this switch statment because
			//  I was getting a wired issue where It always 
			// printed invalid input even if I typed Y or N.
		
							
			printf("Do you want to decode another resistor?\n");
			printf(" => ");
			scanf(" %c", &choice);

			switch(choice) {

				case 'Y' :
					printf("Starting new ohm calculator\n");
					i--;
					j++;
					break;
				case 'y':
					printf("Strating new ohm calculator\n");
					i--;
					j++;
					break;
				case 'N' :
					printf("Thank you for using my ohm cacluator\n");
					L++;
					j++;
					break;
				case 'n' :
					printf("Thank you for using my ohm cacluator\n");
					L++;
					j++;
					break;
				default :
					printf("Invalid input!\n");
					printf("Type Y to calculate a new resistor\n");
					printf("Type N to stop calculating\n");
			}

		}while( j < 1);
	}
	
	return 0;


}

