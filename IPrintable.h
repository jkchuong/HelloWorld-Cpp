#pragma once
#include <iostream>

class IPrintable // Interface - only contains pure virtual functions
{
	// friend so 
	friend std::ostream& operator<<(std::ostream& os, const IPrintable& obj);

public:
	virtual void print(std::ostream& os) const = 0;
};

