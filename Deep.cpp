#include "Deep.h"

Deep::Deep(int d)
{
	data = new int; // Allocate storage
	*data = d;
}

Deep::~Deep()
{
	delete data; // Free storage
	std::cout << "Destructor freeing data\n";
}

// create new storage and copy values
Deep::Deep(const Deep& source)
{
	data = new int; // Allocate storage
	*data = *source.data; // Set the data it points to to a copy of the original data
	std::cout << "Copy constructor - deep\n";
}

// delegating copy constructor - Does the same as above
//Deep::Deep(const Deep& source) : Deep{*source.data}
//{
//	std::cout << "Copy constructor - deep\n";
//}

void Deep::set_data_value(int d)
{
	*data = d;
}

int Deep::get_data_value()
{
	return *data;
}

