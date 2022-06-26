#include "Circle.h"

void Circle::draw()
{
	std::cout << "Drawing a circle\n";
}

void Circle::rotate()
{
	std::cout << "Rotating a circle\n";
}

void Circle::print(std::ostream& os) const
{
	std::cout << "Print circle";
}

Circle::~Circle()
{
	std::cout << "Deconstructing a circle\n";
}