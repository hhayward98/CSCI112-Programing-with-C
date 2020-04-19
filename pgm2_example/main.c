#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

int main(void) {

    Node_t* list_head = NULL;

    FILE* fptr = fopen("ids.txt", "r");

    char line[80];
    char* result;

     while (fgets(line, 80, fptr) != NULL) {

        Student_t* st = malloc(sizeof(Student_t));

        result = strtok(line, ",");
        strcpy(st->last_name, result);

        result = strtok(NULL, ",");
        strcpy(st->first_name, result);

        result = strtok(NULL, ",");
        sscanf(result, "%d", &st->id);

        ListInsert(&list_head, st);
    }

    Sort(&list_head);

    Node_t* cur = list_head;
    while (cur != NULL) {
        printf("first name: %-7s last_name: %-9s id: %d\n",
                cur->st->first_name, cur->st->last_name,
                cur->st->id);
        cur = cur->next;
    }
    return(0);
}
