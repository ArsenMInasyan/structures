#include <array.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main() 
{
	struct array* my_array = array_create();
	array_pushback(my_array, 'a');
	array_pushback(my_array, 'b');
	array_pushback(my_array, 'c');
	array_pushback(my_array, 'd');
	array_pushback(my_array, 'e');
	array_print(my_array);
	printf("Array Test Passed\n");
	return 0;
}
