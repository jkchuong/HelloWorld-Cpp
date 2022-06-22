#pragma once
#include <iostream>

class Shallow
{
private:
	int* data;

public:
	Shallow(int d);                  // Constructor
	Shallow(const Shallow& source);  // Copy Constructor
	~Shallow();

	void set_data_value(int d);
	int get_data_value();
};

