#include <array.hpp>
#include <iostream>
#include <cstddef>
#include <string>
#include <cassert>
#include <cstdlib>

int main()
{
	array my_array;
        my_array.push_back('1');
        my_array.push_back('2');
        my_array.push_back('3');
        my_array.push_back('4');
        my_array.push_back('5');
        my_array.push_back('6');
        my_array.push_back('7');
        my_array.push_back('8');
        my_array.push_back('9');
        my_array.push_back('a');
        my_array.push_back('b');
        my_array.insert('c', 3);
        my_array.insert('j', 0);
        my_array.remove_element_by_index(3);
        my_array.remove_element_by_value('8');
        array new_array;
        new_array = my_array;
        my_array.push_back('l');
        my_array.print();
        new_array.print();
        return 0;

}

