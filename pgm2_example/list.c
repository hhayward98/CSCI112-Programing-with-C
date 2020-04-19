#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void ListInsert(Node_t** head, Student_t* st) {

    // insert at the head
    Node_t* new_node = malloc(sizeof(Node_t));
    new_node->st = st;
    new_node->next = NULL;

    Node_t* old_head = *head;
    *head = new_node;

    new_node->next = old_head;

    return;
} 
