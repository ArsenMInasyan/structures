// Data structures

struct node; // node of the list
struct list; // list

// Functions

/*
 * "list_insert" is a function to insert the node data into the list after the given node in list
 * num is the data of the node
 * n is the node 
 * l is the list
 */

void list_insert(int num, struct node* n, struct list* l);

/*
 * "list_return_node_data" is a function to return the data of the node that is in the given position in the list
 * l is the list
 * n is the node
 * if pos is bigger than list length than error is returned
 */

int list_return_node_data(struct node* n);

/*
 * "list_find_data" is a function to find the given data's position in the list
 * l is the list
 * num is the data
 * function returns the node if finding the data in list and 0 if not
 */

struct node* list_find_data(struct list* l, int num);

/*
 * "list_node_remove" is a function to remove the next node of the given node from the list
 * l is the list
 * n is the node
 */

void list_node_remove(struct list* l, struct node* n);
