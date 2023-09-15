#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

struct tree_node
{
	int num;
	struct tree_node* right;
	struct tree_node* left;
	int height;
};

struct tree
{
	struct tree_node* root;
};

struct tree_node* tree_node_create(int num)
{
	struct tree_node* node = (struct tree_node*) malloc(sizeof(struct tree_node));
	node->num = num;
	node->left = 0;
	node->right = 0;
	node->height = 1;
	return node;
}

struct tree* tree_create()
{
	struct tree* t = (struct tree*)malloc(sizeof(struct tree));
	t->root = 0;
	return t;
}

int max(int a, int b) {
	return (a > b ? a : b);
}

int tree_get_height (struct tree_node* root) {
	if (0 != root) {
		return root->height;
	} else {
		return 0;
	}
}

struct tree_node* tree_right_rotate(struct tree_node* y) {
	struct tree_node* x = y->left;
	struct tree_node* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(tree_get_height(y->left), tree_get_height(y->right) + 1);
	x->height = max(tree_get_height(x->left), tree_get_height(x->right) + 1);

	return x;
}

struct tree_node* tree_left_rotate(struct tree_node* x) {
	struct tree_node* y = x->right;
	struct tree_node* T2 = y->left;

	y->left = x;
	x->right = T2;

	y->height = max(tree_get_height(y->left), tree_get_height(y->right) + 1);
	x->height = max(tree_get_height(x->left), tree_get_height(x->right) + 1);

	return y;
}

int tree_is_balanced (struct tree_node* root) {
	if (0 == root) {
		return 0;
	} else {
		return (tree_get_height(root->left) - tree_get_height(root->right));
	}
}

struct tree_node* tree_balance_node(struct tree_node* root, int num) {

	int is_balanced = tree_is_balanced(root);

	if (is_balanced > 1 && num < root->left->num) {
		return tree_right_rotate(root);
	}	

	if (is_balanced < -1 && num > root->right->num) {
		return tree_left_rotate(root);
	}	

	if (is_balanced > 1 && num > root->left->num) {
		root->left = tree_left_rotate(root->left);
		return tree_right_rotate(root);
	}	

	if (is_balanced < -1 && num < root->right->num) {
		root->right = tree_right_rotate(root->right);
		return tree_left_rotate(root);
	}	

	return root;
}

struct tree_node* tree_insert_node(struct tree_node* root, int num) {

	if (0 == root) {
		return tree_node_create(num);
	}

	if (num < root->num) {
		root->left = tree_insert_node(root->left, num);
	} else {
		root->right = tree_insert_node(root->right, num);
	}

	root->height = max(tree_get_height(root->left), tree_get_height(root->right)) + 1;

	return tree_balance_node(root, num);
}

void tree_insert(struct tree* t, int num)
{
	assert(0 != t);
	if (t->root != 0) {
		t->root = tree_insert_node(t->root, num);
	} else {
		t->root = tree_node_create(num);
	}
}

void tree_insert_array(struct tree* t, int arr[], int size) 
{
	assert(0 != t);
	assert(0 < size);
		for (int i = 0; i < size; i++) {
			if (t->root != 0) {
				tree_insert(t, arr[i]);
			} else {
				t->root = tree_node_create(arr[i]);
			}
		}
}

void tree_insert_file_data(struct tree* t, char* file) {
	assert(0 != t);
	FILE *nums;
	int capacity = 10000000;
	nums = fopen(file, "r");
	int* nums_array = (int*)malloc(capacity*sizeof(int));
	assert(NULL != nums);
	int i = 0;
	int num;
	while (!feof(nums)) {
		if(i == capacity){
			nums_array = (int*)realloc(nums_array, 100*capacity*sizeof(int));
		}
		fscanf(nums, "%d", &nums_array[i]);
		i++;
	}
	fclose(nums);
		
	tree_insert_array(t, nums_array, i - 1);
}

void tree_preorder(struct tree_node* root) 
{
	assert(0 != root);
	printf("%d ", root->num);
	if (0 != root->left) {
		tree_preorder(root->left);
	}
	if (0 != root->right) {
		tree_preorder(root->right);
	}
}

void tree_preorder_print(struct tree* t) 
{
	assert(0 != t);
	if (t->root != 0) {
		tree_preorder(t->root);
		printf("\n");
	}
}

void tree_remove_element(struct tree_node* root, int el) {
	assert(0 != root);
	if (0 != root->left) {
		if (root->left->num == el) {
			root->left = 0;
		} else {
			tree_remove_element(root->left, el);
		}
	}
	if (0 != root->right) {
		if (root->right->num == el) {
			root->right = 0;
		} else {
			tree_remove_element(root->right, el);
		}
	}
}

void tree_remove(struct tree* t, int el) 
{
	assert(0 != t);
	if (t->root != 0) {
		tree_remove_element(t->root, el);	
	} else {
		printf("Node is empty\n");
	}
}

int tree_size_helper(struct tree_node* root) 
{
	assert(0 != root);
	int size = 1;
	if (0 != root->left) {
		size += tree_size_helper(root->left);
	}
	if (0 != root->right) {
		size += tree_size_helper(root->right);
	}
	return size;
}

int tree_size(struct tree* t) 
{
	assert(0 != t);
	if (0 == t->root) {
		return 0;
	}
	return tree_size_helper(t->root);
}

int tree_height_helper(struct tree_node* root) 
{
	if (!root)
        	return 0;
    	else {
        	int left_height = tree_height_helper(root->left);
        	int right_height = tree_height_helper(root->right);
        	if (left_height >= right_height) {
            		return left_height + 1;
		}
        	else {
            		return right_height + 1;
		}
	}
}

int tree_height(struct tree* t) {
	assert(0 != t);
	if (0 == t->root) {
		return 0;
	}
	return tree_height_helper(t->root);

}

int tree_empty(struct tree* t)
{
	return (t->root == 0);
}


int main() {

	struct tree* t = tree_create();
	assert(tree_size(t) == 0);
	assert(tree_empty(t));
//	tree_insert(t, 10);
//	tree_insert(t, 20);
//	tree_insert(t, 30);
//	tree_insert(t, 40);
//	tree_insert(t, 50);
//	tree_insert(t, 25);
	
	//int nums_array[15] = {5, 6, 20, 14, 15, 16, 17, 18, 26, 13, 19, 28, 30, 25, 45};
	//int nums_array[] = {75, 62, 67, 56, 88, 100, 25, 12, 32, 6, 45, 23, 24};
	//tree_insert_array(t, nums_array, sizeof(nums_array)/sizeof(nums_array[0]));
	tree_insert_file_data(t, "numbers.txt");
	//tree_remove(t, 16);
	
	tree_preorder_print(t);

	int cur_size = tree_size(t);
	int cur_height = tree_height(t);
	printf("\nsize: %d\n", cur_size);
	printf("\nheight: %d\n", cur_height);
}
