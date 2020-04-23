#include <stdio.h>
#include "pgm2.h"

void SortedInsert(Node_t**, Node_t**);


void sort(Node_t** head) {
	Node_t* sorted = NULL;// sorted list.


	Node_t* cur = *head;

	while (cur != NULL) {
		
		Node_t* next = cur->next;
		SortedInsert(&sorted, &cur);

		cur = next;
	}
	*head = sorted;
	return;
}


void SortedInsert(Node_t** head, Node_t** new_node) {

	Node_t* cur;
	Node_t* test_node;
	test_node = *new_node;
	// test for the highest grade then 
	//  puts the new new node in the correct spot	
	if (*head == NULL || (*head)->c112->Grade < test_node->c112->Grade) {

		test_node->next = *head;
		*head = test_node;
	}
	else {
		cur = *head;
		while (cur->next != NULL && cur->next->c112->Grade > test_node->c112->Grade) {
			cur = cur->next;
		}

		test_node->next = cur->next;
		cur->next = test_node;
	}
	return;
}



