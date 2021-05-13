#pragma once
#include <iostream>

template<typename T>
void print_array(T* array, int length)
{
	for (int i = 0; i < length; i++)
		std::cout << array[i] << " ";
}