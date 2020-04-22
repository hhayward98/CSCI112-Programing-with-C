#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgm2.h"


void ListInsert(Node_t** head, Student_t* c112) {

	Node_t* new_node = malloc(sizeof(Node_t));
	new_node->c112 = c112;
	new_node->next = NULL;

	Node_t* old_head = *head;
	*head = new_node;
	new_node->next = old_head;

	return;
}

