#include <iostream>

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}