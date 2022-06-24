#pragma once
#include <iostream>

class Deep
{
private:
	int* data;  // Pointer - only really need this when class contains pointer attributes

public:
	Deep(int d);               // Constructor
	Deep(const Deep& source);  // Deep Copy Constructor
	~Deep();                   // Destructor 

	void set_data_value(int d);
	int get_data_value();
};

