typedef struct {
    char last_name[40];
    char first_name[40];
    int id;
} Student_t;

typedef struct node_t {
    Student_t* st;
    struct node_t *next;
} Node_t;

void ListInsert(Node_t**, Student_t*);
void Sort(Node_t**);

