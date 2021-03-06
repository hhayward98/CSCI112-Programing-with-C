#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// compairs the char in temp to the char in key[]
// finds its position in key and compairs its position to the position in ref[]
// then assigns the char of that positon in ref to the char of temp.  
char substitution(char key[],char temp[]){

	char ref[27] = "abcdefghijklmnopqrstuvwxyz";
	int temp2;

	
	for (int i = 0; i < strlen(ref); i++){
		
		if (temp[0] == ref[i]){
			
			temp2 = i;
			// compair i to the index of ref and take the char from that.
			for (int k = 0; k < strlen(key); k++) {		
				if (temp2 == k) {
					
					return key[k];
				}
			}
		
		}

	
	}



	return 0;
}




int main(void) {

	FILE *file_in;
	FILE *file_out;
	//file = fopen("tinyTale.txt", "r+");
	file_in = fopen("/public/examples/lab6/tinyTale.txt", "r");
	if(file_in == NULL){
		printf("Error!, no such file");
		exit(1);
	}
	file_out = fopen("encrypted_message.txt", "w");
 	
	
	char key[27] = "efghijklmnopqrstuvwxyzabcd";
	char temp[120];
	char newStr[120];
	char temp_char[10];
	char upp[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	
	int bufferLength = 60;
	char buffer[bufferLength];

	// grabs the string and stores it in buffer
	while(fgets(buffer, bufferLength, file_in)) {
		fprintf(file_out, "%s\n", buffer);	
		// grabs each char in buffer and copys it to temp.	
		for (int i = 0; i < bufferLength; i++) {
			strncpy(temp, &buffer[i], 1);
			temp[1] = '\0';
			
			//stops the error of a extra char in encrypted message.
			if (strlen(newStr) == strlen(buffer)) {
				break;
			}
			
			

			if (temp[0] != ' '){

				for (int l = 0; l < strlen(upp); l++) {
					if (temp[0] == upp[l]) {
						strcat(newStr, &upp[l]);
					}
				}
				// if the char in temp is not a space we will do the substitution 
				// and add the char to the new string
				temp_char[0] = substitution(key, temp);
				strcat(newStr, &temp_char[0]);
			}
			// if the char in the string is a space then we will add a spce to the newstring
			else {
				strcat(newStr, " ");
			}
			
		}
		fprintf(file_out, "%s\n", newStr);
		printf("\n");
		newStr[0] = '\0';
	}

		
	fclose(file_out);
	fclose(file_in);
	return 0;
}
