#include <stdio.h>
#include "student.h"

void SortedInsert(Node_t**, Node_t*);

// Implements the selection sort
// algorithm
void Sort(Node_t** head) {
   Node_t* sorted = NULL;

    Node_t* cur = *head;
    while (cur != NULL) {

        Node_t* next = cur->next;

        SortedInsert(&sorted, cur);

        cur = next;
    }

    *head = sorted;
    return;
}

// move each node to the sorted linked list into the
// right sorted position in that list
void SortedInsert(Node_t** head, Node_t* new_node) {

    Node_t* cur;

    // special case for making new node the head
    if (*head == NULL || 
        (*head)->st->id > new_node->st->id) {

        new_node->next = *head;
        *head = new_node;
    }
    else {
        cur = *head;
        while (cur->next != NULL &&
              cur->next->st->id < new_node->st->id) { 

            cur = cur->next;
        }
        new_node->next = cur->next;
        cur->next = new_node;
    }
    return;
}
