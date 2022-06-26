#include "Square.h"

void Square::draw()
{
	std::cout << "Drawing a Square\n";
}

void Square::rotate()
{
	std::cout << "Rotating a Square\n";
}

void Square::print(std::ostream& os) const
{
	std::cout << "Print square";
}

Square::~Square()
{
	std::cout << "Deconstructing a Square\n";
}