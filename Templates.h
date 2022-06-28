#pragma once
#include <iostream>
#include <string>
#include <vector>

/*
*  Should probaby change this to Item.h and My_Pair.h but I already have too many files right now
*/

// Template classes contained entirely in header file
template <typename T>
class Item
{
	std::string name;
	T value;
public:
	Item(std::string name, T value) : name{name}, value{value} {}
	
	std::string get_name() const 
	{
		return name; 
	}
	
	T get_value() const
	{
		return value;
	}
};

template <typename T1, typename T2>
struct My_Pair
{
	T1 first;
	T2 second;
};

// std::array exists - use instead of base array
// Using non-type template parameters
template<typename T, int N>
class Array
{
	int size{ N };
	T values[N];

	friend std::ostream& operator<<(std::ostream& os, const Array<T, N>& arr)
	{
		os << "[ "; 
		for (const auto& val : arr.values)
			os << val << " ";
		os << "]" << std::endl;
		return os;
	}

public:
	Array() = default;
	Array(T init_val)
	{
		for (auto& item : values)
			item = init_val;
	}

	void fill(int val)
	{
		for (auto& item : values)
			item = val;
	}

	int get_size() const
	{
		return size;
	}

	T& operator[](int index) // overload subscript operator
	{
		return values[index];
	}


};