#pragma once
#include "Shape.h"

class Circle : public Shape // concrete class
{
	virtual void draw() override;
	virtual void rotate() override;
	
	virtual void print(std::ostream& os) const override;

	virtual ~Circle();
};

