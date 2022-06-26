#pragma once
#include "Shape.h"
class Square : public Shape
{
	virtual void draw() override;
	virtual void rotate() override;
	virtual void print(std::ostream& os) const override;

	virtual ~Square();
};

