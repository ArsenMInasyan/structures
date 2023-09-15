#include "array.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MIN_CAP 16

struct array {
	char* vec;
	int size;
	int capacity;
};

struct array* array_create()
{
	struct array* arr = (struct array*) malloc(sizeof(struct array));
	arr->vec = (char*) malloc(MIN_CAP * sizeof(char));
	arr->size = 0;
	arr->capacity = MIN_CAP;
	return arr;
}

void array_shift_left(struct array* arr, int ind)
{
	assert(0 != arr);
	assert(array_size(arr) > 0);
	assert(array_size(arr) > ind && ind >= 0);
	for (int i = ind; i < arr->size - 1; i++) {
		arr->vec[i] = arr->vec[i + 1];
	}
	arr->size--;
}

void array_shift_right(struct array* arr, int ind) 
{
        assert(0 != arr);
        assert(arr->size > 0);
	assert(arr->size < arr->capacity);
	assert(arr->size >= ind && ind >= 0);
	printf("Index: %d\n", ind);
	for (int i = array_size(arr); i >= ind; i--) {
		arr->vec[i + 1] = arr->vec[i];
	}
	arr->size++;
}

void array_pushback(struct array* arr, char sym) {
	assert(0 != arr);
	assert(array_size(arr) < array_capacity(arr));
	if (arr->size == 0) {
		arr->vec[0] = sym;
		arr->size++;
	} else {
		if (array_size(arr) == array_capacity(arr)) {
			array_extend_capacity(arr, array_capacity(arr) * 2);
		}
		arr->vec[arr->size] = sym;
		arr->size++;
	}
}

void array_print(struct array* arr) {
	assert(0 != arr);
	assert(array_size(arr) < array_capacity(arr));
	if (arr->size == 0) {
		printf("Array is empty\n");
	} else {
		printf("[ ");
		for (int i = 0; i < arr->size; i++) {
			if (i == arr->size - 1){
				printf("%c", arr->vec[i]);
			} else {
				printf("%c, ", arr->vec[i]);
			}
		}
		printf(" ]\n");
	}
}

void array_insert(struct array* arr, char sym, int ind)
{
	assert(0 != arr);
	assert(array_size(arr) < array_capacity(arr));
	assert(ind <= arr->size && ind >= 0);
	array_shift_right(arr, ind - 1);
	arr->vec[ind - 1] = sym;
}

int array_return_index_by_data(struct array* arr, char sym)
{
	assert(0 != arr);
	for (int i = 0; i < array_size(arr); i++) {
		if (arr->vec[i] == sym) {
			return i;
		}
	}
	printf("No Character\n");
	return 0;
}

int array_size(struct array* arr)
{
	assert(0 != arr);
	assert(arr->size >= 0);
	return arr->size;
}

int array_capacity(struct array* arr)
{
	assert(0 != arr);
	assert(arr->capacity > 0);
	return arr->capacity;
}

void array_extend_capacity(struct array* arr, int cap)
{
	assert(0 != arr);
	assert(arr->capacity > 0);
	assert(cap > arr->capacity);

	char* new = (char*) malloc(arr->capacity * sizeof(char));
	memcpy(new, arr->vec, arr->capacity);
	free(arr->vec);
	arr->vec = (char*) malloc(cap * sizeof(char));
	memcpy(arr->vec, new, arr->capacity);
	free(new);
	arr->capacity = cap;
}

void array_remove_node_by_index(struct array* arr, int ind)
{
	assert(0 != arr);
	assert(array_size(arr) > 0);
	assert(ind < array_size(arr) && ind >= 0);
	array_shift_left(arr, ind - 1);
}

void array_remove_node_by_char(struct array* arr, char sym) 
{
	assert(0 != arr);
	assert(array_size(arr) > 0);
	for (int i = 0; i < array_size(arr); i++) {
		if (arr->vec[i] == sym) {
			array_shift_left(arr, i);
		}
	}
}

void array_destroy(struct array* arr)
{
	assert(0 != arr);
	free(arr);
}

int main() {
	struct array* my_array = array_create();
	assert(array_size(my_array) == 0);
	assert(array_capacity(my_array) > array_size(my_array));
	array_pushback(my_array, 'a');
	array_pushback(my_array, 'b');
	array_pushback(my_array, 'c');
	array_pushback(my_array, 'd');
	array_pushback(my_array, 'f');
	array_pushback(my_array, 'g');
	array_pushback(my_array, 'h');
	array_pushback(my_array, 'i');
	array_insert(my_array, 'e', 5);
	array_remove_node_by_char(my_array, 'f');


	printf("Size: %d\n", array_size(my_array));
	printf("Capacity: %d\n", array_capacity(my_array));
	array_print(my_array);
	array_destroy(my_array);
	return 0;
}
