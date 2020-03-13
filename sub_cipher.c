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

char substitution_up(char key[],char temp[]){

	char ref[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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



// need to add a function that will substitute out the upper case char

int main(void) {
	
	char fileIN[40];

	printf("Enter in the Path to the file to encode: ");
	
	scanf("%s", &fileIN[0]);
	

	FILE *file_in;
	FILE *file_out;
	//file = fopen("tinyTale.txt", "r+");
	file_in = fopen(fileIN, "r");
	if(file_in == NULL){
		printf("Error!, no such file");
		exit(1);
	}
	file_out = fopen("encrypted_message.txt", "w");
 	
	
	char key[27];
	char key_up[27];
	char temp[225];
	char newStr[225];
	char temp_char[10];
	char upp[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	
	int bufferLength = 225;
	char buffer[bufferLength];
	
	printf("Enter in the encyption key in Lowercase: ");
	scanf("%s", &key[0]);	


	printf("Enter in the encyption key in uppcase: ");
	scanf("%s", &key_up[0]);

	

	// grabs the string and stores it in buffer
	while(fgets(buffer, bufferLength, file_in)) {
		printf("%s\n", buffer);	
		printf("%s\n", newStr);
		// grabs each char in buffer and copys it to temp.	
		for (int i = 0; i < bufferLength; i++) {
			strncpy(temp, &buffer[i], 1);
			temp[1] = '\0';
			
			// need to add one more if statement for special char
			
			if (strlen(newStr) == strlen(buffer)){
				break;
			}
			
			if (temp[0] != ' '){
		
				// if the char in temp is not a space we will do the substitution 
				// and add the char to the new string
				for (int l = 0; l < strlen(upp); l++) {

					if (temp[0] == upp[l]) {
						temp_char[0] = substitution_up(key_up, temp);
						strcat(newStr, &temp_char[0]);
					}
				 
				// if the char in temp is not a space we will do the substitution 
				// and add the char to the new string
				}

				temp_char[0] = substitution(key, temp);
				strcat(newStr, &temp_char[0]);
			
				
			}
			// if the char in the string is a space then we will add a spce to the newstring
			else {
				strcat(newStr, " ");
					       	
			}	


			
		}
			
		printf("%s\n", newStr);
		printf("\n");
		memset(newStr, 0, sizeof(buffer));
		for (size_t i = 0; i < strlen(buffer); i++){
			newStr[i] = 0;
		}
		//newStr[0] = '\0';
	}

	

	fclose(file_out);
	fclose(file_in);
	return 0;
}
