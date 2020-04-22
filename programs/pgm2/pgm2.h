

typedef struct {

	char First_name[40];
	char Last_name[40];
	double Grade;
	char LG[2];

} Student_t;

// creates the node to be used in a linked list
typedef struct node_t {
	Student_t* c112;
	struct node_t *next;
} Node_t;

// creates the list for the nodes
void ListInsert(Node_t**, Student_t*);
void sort(Node_t**);
