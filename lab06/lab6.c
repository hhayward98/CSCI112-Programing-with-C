#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// compairs the char in temp to the char in key[]
// finds its position in key and compairs its position to the position in ref[]
// then assigns the char of that positon in ref to the char of temp.  
char substitution(char key[],char temp[]){

	char ref[27] = "abcdefghijklmnopqrstuvwxyz";
	int temp2;
	//printf("%c\n", temp[0]);
	
	for (int i = 0; i < strlen(key); i++){
		//if (temp[0] != key[i]) {
		
		//}
		if (temp[0] == key[i]){
			//printf("%d\n", i);
			temp2 = i;
			// compair i to the index of ref and take the char from that.
			for (int k = 0; k < strlen(ref); k++) {
				//printf("%d", temp2);
				//printf("%d\n", k);		
				if (temp2 == k) {
					//printf("char is %c\n", ref[k]);
					return ref[k];
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

	
	int bufferLength = 60;
	char buffer[bufferLength];

	// grabs the string and stores it in buffer
	while(fgets(buffer, bufferLength, file_in)) {
		fprintf(file_out, "%s\n", buffer);	
		// grabs each char in buffer and copys it to temp.	
		for (int i = 0; i < bufferLength; i++) {
			strncpy(temp, &buffer[i], 1);
			temp[1] = '\0';
		//	printf("%s", temp);
			if (temp[0] != ' '){

				temp_char[0] = substitution(key, temp);
				strcat(newStr, &temp_char[0]);
			}
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
