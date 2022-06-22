#include "Shallow.h"

Shallow::Shallow(int d)
{
	data = new int; // allocate storage
	*data = d;
}

Shallow::~Shallow()
{
	delete data; // free storage
	std::cout << "Destructor freeing data\n";
}

// Only pointer is copied, not the data the pointer is pointing to
Shallow::Shallow(const Shallow& source) : data(source.data)
{
	std::cout << "Copy constructor - shallow\n"; // Same as default copy
}

void Shallow::set_data_value(int d)
{
	*data = d;
}

int Shallow::get_data_value()
{
	return *data;
}

