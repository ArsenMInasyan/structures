#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

class array 
{
public:
	size_t get_size() const;
	size_t get_capacity() const;
	void push_back(char sym);
	void insert(char sym, size_t index);
	void print() const;
	void remove_element_by_index(size_t index);
	void remove_element_by_value(char sym);
	int find(char sym) const;

private:
	char* m_array;
	size_t m_size;
	size_t m_capacity;
	void reserve();

private:
	void array_helper(const array &a);
	void shift_left(size_t index);
	void shift_right(int index);

public:
	array(size_t s = 0);
	~array();
	array(const array &a);
	array& operator=(const array &a);
};

#endif
