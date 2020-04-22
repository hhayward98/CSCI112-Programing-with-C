#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold number

typedef struct {
	int num1;
} Data_t;

// struct for node in linked list
typedef struct node_t {
	Data_t * d;
	struct node_t *next;
} Node_t;

// functions needed
void Read(Node_t** head) {
	FILE* file_in = fopen("in.txt", "r");

	if (file_in == NULL) {
			printf("Eroor!, no such file");
			exit(1);
	}

	int num_read;
	while (fscanf(file_in, "%d", &num_read) > 0) {
		// have to do this each time to get new adress
		Data_t* d = malloc(sizeof(Data_t));
		d->num1 = num_read;

		ListInsert(head, d);
	}
	return;
}

// sorts the nodes in a list by creating a new list and adding 
// the right node in order to the new list
void Sort(Node_t**) {
	// startsnew list
	Node_t* sorted = NULL;

	// this pointer is the first node in the unsorted list
	Node_t* cur = *head;
	while (cur != NULL) {

		// we have to hold on to the next node 
		// because the call to sort insert may change our cur pointer
		Node_t* next = cur->next;

		// insert our current node into the sorted list 
		// in the right place
		SortedInsert(&sorted, cur);

		cur = next;
	}

	// head now points to the head of the sorted list
	*head = sorted;
	return;
}


void Print(Node_t**) {
	FILE* file_out = fopen("out.txt", "w");

	Node_t* cur = head;
	While (cur != NULL) {
		fprintf(file_out, "%d\n", cur->d->num1);
		cur = cur->next;
	}
	return;
}

void ListInsert(Node_t** head, Data_t* d) {
	//insert at the head
	Node_t* new_node = malloc(sizeof(Node_t));
	new_node->d = d;

	Node_t* old_head = *head;
	*head = new_node;

	new_node->next = old_head;

	return; 
}

void SortedInsert(Node_t** head, Node_t* new_node) {

	Node_t* cur;

	// special case for making new node
	if (*head == NULL || (*head)->d->num1 >= new_node->d->num1) {

		new_node->next = *head;
		*head = new_node;
	}
	else {
		cur = *head;
		// find the right node to insert the new node in front of
		while (cur->next != NULL &&
				cur->next->d->num1 < new_node->d->num1) {

			cur = cur->next;
		}
		new_node->next = cur->next;
		cur->next = new_node;
	}
	return;
}


int main(void) {

	// empty linked list
	Node_t* List_head = NULL;

	// read in the file and put the data into a linked list
	Read(&list_head);

	// sort list by num1 from lowest to highest 
	Sort(&list_head);

	// print out list
	Print(list_head);

	return(0);
}


