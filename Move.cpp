#include "Move.h"

void Move::set_data_value(int d)
{
	*data = d;
}

int Move::get_data_value()
{
	return *data;
}

// Constructor
Move::Move(int d)
{
	data = new int;
	*data = d;
	std::cout << "Constructor for: " << d << '\n';
}

// Deep copy constructor
Move::Move(const Move& source) : Move{*source.data}
{
	std::cout << "Copy constructor - deep copy for: " << *data << '\n';
}

// Move Constructor
// Equivalent to shallow copy except we null out source pointer
Move::Move(Move&& source) noexcept : data{source.data} // copy source pointer to new pointer
{
	source.data = nullptr; // null out source pointer
	std::cout << "Move constructor - moving resource: " << *data << '\n';
}

Move::~Move()
{
	if (data != nullptr)
	{
		std::cout << "Destructor freeing data for: " << *data << '\n';
	}
	else
	{
		std::cout << "Destructor freeing data for nullptr" << '\n';
	}

	delete data;
}