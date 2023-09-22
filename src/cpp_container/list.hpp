#ifndef LIST_H
#define LIST_H

#include <cstddef>


class list_node
{

private:
	int num;
	list_node* next;
}

class list
{

public:
	void create_list();

private:
	list_node head;

}

#endif
