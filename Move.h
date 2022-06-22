#pragma once
#include <iostream>

class Move
{
private:
	int* data;

public:
	void set_data_value(int d);
	int get_data_value();

	Move(Move&& source) noexcept; // Move Constructor
	Move(int d);                  // Constructor
	Move(const Move& source);     // Copy Constructor
	~Move();                      // Destructor
};

