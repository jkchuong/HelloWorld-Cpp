#pragma once
#include <cstring>
#include <iostream>
#include <string.h>

class Mystring
{
private:
	char* str; // pointer to char[] that holds C-style string

public:
	Mystring();                        // No args constructor
	Mystring(const char* s);           // Constructor with c-style string literal
	Mystring(const Mystring& source);  // Copy constructor
	~Mystring();                       // Destructor

	void display() const;
	int get_length() const;
	const char* get_str() const;

	Mystring& operator=(const Mystring& rhs);   // Overloading copy operator (assignment)
	Mystring& operator=(Mystring&& rhs);        // Overloading move operator (assignment)

	Mystring operator-() const;                 // Overloading unary minus operator
	bool operator==(const Mystring& rhs) const; // Overloading comparison operator
};

