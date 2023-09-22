#include "array.hpp"
#include <iostream>
#include <cstddef>
#include <string>
#include <cassert>
#include <cstdlib>

array::array(size_t s) 
{
	m_size = s;
	m_capacity = 16;
	m_array = new char[m_capacity];
}

array::~array()
{ 
	delete[] m_array; 
}

void array::array_helper(const array &a) 
{
	m_size = a.m_size;
	m_capacity = a.m_capacity;
	m_array = new char[m_capacity];

	for (size_t i = 0; i < m_size; i++) {
		m_array[i] = a.m_array[i];
	}
}

array::array(const array &a) 
{
	array_helper(a);
}

array& array::operator=(const array &a) 
{
	delete[] m_array; 
	array_helper(a);

	return *this;
}

void array::reserve() {
	m_capacity *= 2;
	m_array = (char*)realloc(m_array, m_capacity);
}

size_t array::get_size() const
{
	return m_size;
}

size_t array::get_capacity() const
{
	return m_capacity;
}

int array::find(char sym) const 
{
	assert(0 != m_array);
	assert(m_size >= 0);
	for (size_t i = 0; i < m_size; i++) {
		if (m_array[i] == sym) {
			return i;
		}
	}
	return -1;
}

void array::push_back(char sym)
{
	assert(0 != m_array);
	if (m_size == m_capacity){
		reserve();	
	}

	m_array[m_size] = sym;
	m_size++;
}

void array::shift_right(int index)
{
	for (int i = m_size - 1; i >= index; i--){
		m_array[i + 1] = m_array[i];
	}
	m_size++;
}

void array::shift_left(size_t index)
{
	for (size_t i = index; i < m_size; i++) {
		m_array[i] = m_array[i + 1];
	}
	m_size--;
}

void array::insert(char sym, size_t index)
{
	assert(index <= m_size);
	assert(index >= 0);
	if (m_size == m_capacity) {
		reserve();	
	}
	shift_right(index);
	m_array[index] = sym;
}

void array::remove_element_by_index(size_t index)
{
	assert(index <= m_size);
	assert(index >= 0);
	shift_left(index);
}

void array::remove_element_by_value(char sym) 
{
	assert(0 != m_array);
	assert(m_size >= 0);
	int index = find(sym);
	remove_element_by_index(index);
}

void array::print() const
{
	std::cout<<"[ ";
	for (size_t i = 0; i < m_size; i++) {
		if (i == m_size - 1) {
			std::cout<<m_array[i];
		} else {
			std::cout<<m_array[i] << ", ";
		}
	}
	std::cout<<" ]\n";
}

int main()
{
	std::cout<<"Creating new array\n";
	array my_array;
	std::cout<<"Pushing 1...\n";
	my_array.push_back('1');
	std::cout<<"Pushing 2...\n";
	my_array.push_back('2');
	std::cout<<"Pushing 3...\n";
	my_array.push_back('3');
	std::cout<<"Pushing 4...\n";
	my_array.push_back('4');
	std::cout<<"Pushing 5...\n";
	my_array.push_back('5');
	std::cout<<"Pushing 6...\n";
	my_array.push_back('6');
	std::cout<<"Pushing 7...\n";
	my_array.push_back('7');
	std::cout<<"Pushing 7...\n";
	my_array.push_back('8');
	std::cout<<"Pushing 9...\n";
	my_array.push_back('9');
	std::cout<<"Pushing a...\n";
	my_array.push_back('a');
	std::cout<<"Pushing b...\n";
	my_array.push_back('b');
	std::cout<<"Inserting c...\n";
	my_array.insert('c', 3);
	std::cout<<"inserting j...\n";
	my_array.insert('j', 0);
	std::cout<<"Print array...\n";
	my_array.push_back('d');
	my_array.push_back('r');
	my_array.push_back('t');
	my_array.push_back('h');
	my_array.push_back('j');
	my_array.push_back('k');
	my_array.push_back('l');
	my_array.push_back('x');
	my_array.push_back('z');
	my_array.push_back('y');
	my_array.print();
	std::cout<<"Print array capacity\n"<<my_array.get_capacity()<<"\n";
	std::cout<<"Remove 4-th element...\n";
	my_array.remove_element_by_index(3);
	std::cout<<"Remove element '8'...\n";
	my_array.remove_element_by_value('8');
	std::cout<<"Print array...\n";
	my_array.print();
	std::cout<<"Creating new array...\n";
	array new_array;
	std::cout<<"Pushing a...\n";
	new_array.push_back('a');
	std::cout<<"Pushing b...\n";
	new_array.push_back('b');
	std::cout<<"Pushing c...\n";
	new_array.push_back('c');
	std::cout<<"Pushing d...\n";
	new_array.push_back('d');
	std::cout<<"Pushing e...\n";
	new_array.push_back('e');
	std::cout<<"Print array size\n"<<new_array.get_size()<<"\n";
	std::cout<<"Print array...\n";
	new_array.print();
	std::cout<<"Copy first created array to second...\n";
	new_array = my_array;
	std::cout<<"Print second array...\n";
	new_array.print();
	return 0;
}
