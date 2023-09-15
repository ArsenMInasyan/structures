 /**
 * @file
 * Struct array represents a linear data structure that stores a collection of
 * chars at contiguous locations in a computer's memory. 
 * The size of an array is the number of elements stored in the array.
 * Array capacity is the number of elements for which memory has been allocated.
 * capacity() is always greater than or equal to size(). 
 */
struct array;

/**
 * @brief Function to create an empty array.
 */
struct array* array_create();

/**
 * @brief Function to insert data into the array in the given index.
 *
 * @param arr is the given array.
 * @param sym is the data.
 * @param ind is the index.
 *
 * @pre ind is smaller or equal to the array size and bigger or equal to 0.
 * @pre Array size is smaller than array capacity.
 *
 * @details If ind is equal to 0 the element is inserted from the start of the array, if it is bigger than 0 and smaller than the size of the array the element is inserted in the given index in the array and if it is equal to the size of the array the element is inserted in the end of the array.
 */
void array_insert(struct array* arr, char sym, int ind);

/**
 * @brief Function to return the index of element in the array with the given data.
 * 
 * @param arr is the array.
 * @param sym is the data.
 * 
 * @return Array size when a node with given the data isn't found in the array.
 */
int array_return_index_by_data(struct array* arr, char sym);

/**
 * @brief Function to return the size of the array.
 *
 * @param arr is the array.
 */
int array_size(struct array* arr);

/**
 * @brief Function to return the capacity of the array.
 *
 * @param arr is the array.
 */
int array_capacity(struct array* arr);

/**
 * @brief Function to extend the capacity of the array.
 *
 * @param arr is the array.
 * @param cap is the new capacity.
 *
 * @pre cap is bigger than the capacity of the array.
 */
void array_extend_capacity(struct array* arr, int cap);

/**
 * @brief Function to remove the node from the array in the given index.
 * 
 * @param arr is the array.
 * @param ind is the index.
 *
 * @pre ind is smaller than the array size and bigger or equal to 0.
 *
 * @details If ind is equal to 0 the first element of the array is removed, if it's bigger than 0 and smaller than the array size the element with the given index is removed and if it's equal to array size - 1, the last element in the array is removed.
 */
void array_node_remove(struct array* arr, int ind);
