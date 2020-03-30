#include <stdio.h>
#include "Address.h"
#include <stdlib.h>
#include <string.h>


int main(void) {

	FILE *file_in;
	FILE *file_out;

	file_in = fopen("ipaddresses.txt", "r");

	if (file_in == NULL) {
		printf("Error! no such file");
		exit(1);
	}
	file_out = fopen("output.txt", "w");
	int i = 0, j;

	int bufferLength = 60;
	char buffer[bufferLength];
	const char d[2] = ".";
	const char s[2] = " ";
	char *token;
	
	address_t IP[10];
	char message[40];	
	char and[10] = " and ";
	int k = 0;

	// reads the file line by line 
	while(fgets(buffer, bufferLength, file_in)) {
		// takes the string and splits it up into seperate parts
		token = strtok(buffer, d);
		i = 0;
		j = 0;
		while( token != NULL) {
			// checks the position of each taken to assingn it to the correct value
			// in the struct. Also the string token is cast to an integer when needed.
			if (j == 0) {
				IP[k].xx = atoi(token);
				
			}
			if (j == 1) {
				IP[k].yy = atoi(token);
				
			}
			if (j == 2) {
				IP[k].zz = atoi(token);
			}
			if (j == 3) { 
				IP[k].mm = atoi(token);
			}
			if (j == 4) {
				strcpy(IP[k].nickname, token);
				
			}
	
			token = strtok(NULL, d);
			i++;
			j++;
			if (i == 3){
				// to get the last digits and the nickname seprated 
				// I used s for the spaces
				token = strtok(token, s);
			}

		}
		k++;	
		

	}
	// compairs the first digits of each IP address and groups the nick names together 
	// based on whether the nicknames share the same network.
	i = 0;
	j = 0;
	for (i = 0; i < k; i++) {
	
		strcpy(message, IP[i].nickname);
		for (j = 0; j < k; j++) {
			
			if (IP[i].xx == IP[j].xx) {
				if (strcmp(IP[i].nickname, IP[j].nickname) != 0) {
					strcat(message, and);
					strcat(message, IP[j].nickname);
							
				}
			}

		}
		
		fprintf(file_out, "Machines %s are on the same local network\n", message);
		fprintf(file_out, "\n");
		message[0] = '\0';
	}	

	

	return 0;
}

