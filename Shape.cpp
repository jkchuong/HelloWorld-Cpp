#include "Shape.h"

Shape::~Shape()
{
	std::cout << "Shape destructor\n";
}

void Shape::print(std::ostream& os) const
{
	os << "Printing shape";
}
