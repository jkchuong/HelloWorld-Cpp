#include "Mystring.h"

// No args constructor
Mystring::Mystring() : str{nullptr}
{
	str = new char[1];
	*str = '\0';// assign null to character
}

// Overloaded constructor
Mystring::Mystring(const char* s) : str{ nullptr }
{
	if (s == nullptr)
	{
		str = new char[1];
		*str = '\0';
	}
	else
	{
		// create char array of length of string + 1 for terminator
		str = new char[std::strlen(s) + 1]; 
		std::strcpy(str, s); // copy input until str
	}
}

// Copy constructor
Mystring::Mystring(const Mystring& source) : str{ nullptr }
{
	str = new char[std::strlen(source.str) + 1];
	std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring()
{
	delete[] str;
}

// Display method
void Mystring::display() const
{
	std::cout << str << ": " << get_length() << std::endl;
}

int Mystring::get_length() const
{
	return std::strlen(str);
}

const char* Mystring::get_str() const
{
	return str;
}

// Overloading copy operator (assignment) - i.e s1 = s2; 
Mystring& Mystring::operator=(const Mystring& rhs)
{
	std::cout << "Copy Assignment\n";

	// "this" is the object on the lhs of the operator
	if (this == &rhs)  // s1 = s1;
		return *this;  // return current object

	delete[] str; // deallocate storage for str since we are going to overwrite it with something else
	str = new char[std::strlen(rhs.str) + 1]; // allocate storage for deep copy
	std::strcpy(str, rhs.str);   // copy from rhs to the lhs

	return *this; // return current by reference for chain assignments - i.e s1 = s2 = s3
}

// Overloading move operator (assignment) - i.e s1 = Mystring{"Joe"};
// Similar to Copy assignment except we take the pointer, not copy it over
Mystring& Mystring::operator=(Mystring&& rhs)
{
	std::cout << "Move Assignment\n";

	if (this == &rhs)  // self assignment
		return *this;  // return current object

	delete[] str;      // deallocate current storage
	str = rhs.str;     // steal the pointer

	rhs.str = nullptr; // null out rhs object since it's still pointing at the thing it was before!

	return *this;      // return current object

}

// Overloading unary minus operator - i.e -s1; 
Mystring Mystring::operator-() const
{
	// define this to mean make lowercase
	char* buff = new char[std::strlen(str) + 1];
	std::strcpy(buff, str);

	for (size_t i{ 0 }; i < std::strlen(buff); i++)
		buff[i] = std::tolower(buff[i]);

	Mystring temp{ buff };
	delete[] buff;
	return temp;
}

// Overloading comparison operator - i.e s1 == s2;
bool Mystring::operator==(const Mystring& rhs) const
{
	if (std::strcmp(str, rhs.str) == 0)
		return true;
	else
		return false;
}