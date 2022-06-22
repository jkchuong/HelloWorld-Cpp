#pragma once
#include <iostream>

class Deep
{
private:
	int* data;  // Pointer

public:
	Deep(int d);               // Constructor
	Deep(const Deep& source);  // Copy Constructor
	~Deep();                   // Destructor 

	void set_data_value(int d);
	int get_data_value();
};

