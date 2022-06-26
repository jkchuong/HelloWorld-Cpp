#pragma once
#include "IPrintable.h"
#include <iostream>
#include <vector>

class Shape : public IPrintable // Abstract Base Class, inherits interface IPrintable
{
private:

public:
	virtual void draw() = 0;    // Pure Virtual function
	virtual void rotate() = 0;  // Must be overriden
	virtual ~Shape();


	// Inherited via IPrintable
	virtual void print(std::ostream& os) const override;

};

