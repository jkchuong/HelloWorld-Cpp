#include "Section12.h"

void double_data(int* int_ptr) // take in a pointer - pass by reference
{
	*int_ptr *= 2;
}

// swap the value stored at address a with the value stored at address b
void swap_12(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void display(const std::vector<std::string>* const v)
{
	for (auto str : *v)
	{
		std::cout << str << " ";
	}

	std::cout << '\n';

	//(*v).at(0) = "Funny";  // first const stops this from being changed
	//v = nullptr;           // second const stops this from being changed
}

// function overloading
void display(const int* array, const int sentinel)
{
	while (*array != sentinel)
	{
		std::cout << *array++ << " "; // increment to next array item after each iteration
	}

	std::cout << '\n';
}

// return pointer from a function
// never return a pointer that's pointed to a local function variable!
int* largest_int(int* int_ptr1, int* int_ptr2)
{
	if (*int_ptr1 > *int_ptr2)
		return int_ptr1;
	else
		return int_ptr2;
}

// returning dynamically allocated memory
int* create_array(size_t size, int init_value = 0)
{
	int* new_storage{ nullptr };

	new_storage = new int[size];
	for (size_t i{ 0 }; i < size; i++)
	{
		*(new_storage + i) = init_value;
	}
	return new_storage;
}

int square(int& n)
{
	return n * n;
}

// DON'T DO THIS - returning address of local variable
int* dont_do_this()
{
	int size{};
	return &size;
}

int* dont_do_this_either()
{
	int size{};
	int* int_ptr{ &size };
	return int_ptr;
}

void print_array_12(const int* array, const size_t size)
{
	for (size_t i{ 0 }; i < size; i++)
	{
		std::cout << array[i] << ' ';
	}

	std::cout << '\n';
}

int* apply_all(const int* array1, const size_t size1, const int* array2, const size_t size2)
{
	/*
	*  E.g array1 = [1, 2, 3, 4, 5]
	*  array2 = [10, 20, 30]
	*  new_array = [10, 20, 30, 40, 50, 20, 40, 60, 80, 100, 30, 60, 90, 120, 150]
	*/

	// size 5 then 3
	// need 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
	// 0 + 0, ... , 0 + 4, 5 + 0, ... 5 + 4, 10 + 0, ... 8 + 4
	// -> (j * size1) + k

	int* new_array{ nullptr };

	size_t new_size = size1 * size2;
	new_array = new int[new_size];

	for (size_t j{ 0 }; j < size2; j++)
	{
		for (size_t k{ 0 }; k < size1; k++)
		{
			*(new_array + ((j * size1) + k)) = (array2[j] * array1[k]);
		}
	}

	return new_array;
}