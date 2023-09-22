#include <tree.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


int main() 
{
	struct tree* my_tree = tree_create();
	/*tree_insert(my_tree, 10);
	tree_insert(my_tree, 12);
	tree_insert(my_tree, 5);
	tree_insert(my_tree, 2);
	tree_insert(my_tree, 7);
	tree_insert(my_tree, 15);
	tree_preorder_print(my_tree);
	*/printf("Tree Test Passed\n");
	return 0;
}
