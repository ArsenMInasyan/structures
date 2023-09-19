#include "list.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct node
{
	int num;
	struct node* next;
};

struct list
{
	struct node* head;
};

struct node* node_create(int num, struct node* next)
{
	struct node* n = (struct node*) malloc(sizeof(struct node));
	n->num = num;
	n->next = next;
	return n;
}

struct list* list_create()
{
	struct list* l = (struct list*) malloc(sizeof(struct list));
        l->head = 0;
        return l;
}

unsigned int list_get_size(struct list* l)
{
	struct node* n = l->head;
	int len = 0;
	while (n != 0) {
		len++;
		n = n->next;
	}
	return len;
}

void list_insert(int num, struct node* n, struct list* l)
{
	assert(0 != l);
	if (n == 0) {
		assert(0 == l->head);
		l->head = node_create(num, 0);
	} else {
		n->next = node_create(num, n->next);
	}
}

int list_return_node_data(struct node* n)
{
	return n->num;
}

struct node* list_find_data(struct list* l, int num)
{
	int len = list_get_size(l);
	assert(len > 0);
	struct node* n = l->head;
	for (int i = 0; i < len; i++) {
		if (n->num == num) {
			return n;
		}
		n = n->next;
	}
	return 0;
}

void list_node_remove(struct list* l, struct node* n)
{
	assert(0 != l);
	assert(list_get_size(l) > 0);
	if (0 == n) {
		l->head = l->head->next;
	} else {
		assert(0 != n->next);
		n->next = n->next->next;
	}
}
