#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// add Linked List

typedef struct node_t {
	int NUM;
	struct node_t * next;
} Node_t;

// Inserts the numbers as they are read from the file

void ListInsert(Node_t** head, int num){
	Node_t* new_node = malloc(sizeof(Node_t));
	new_node->NUM = num;
	new_node->next = NULL;

	Node_t* old_head = *head;
	*head = new_node;
	
	new_node->next = old_head;

	return;


}


int main(void) {

	Node_t* list_head = NULL;

	FILE *file_in = fopen("numbers.txt", "r");

	if (file_in == NULL) {
		printf("Error! File does not exist");
		exit(1);
	}


	int bufferLength = 60;
	char buffer[bufferLength];
	int num;
	while(fgets(buffer, bufferLength, file_in)) {
		num = atoi(buffer);
		ListInsert(&list_head, num);
	}
	// prints the list from the head 
	Node_t* cur = list_head;
	while(cur != NULL) {
		printf("Numbers: %d\n", cur->NUM);

		cur = cur->next;
	}
	
}
