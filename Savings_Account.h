#pragma once

#include "Account.h"
#include <iostream>
#include <string>

// final keyword shows this class cannot be derived from - can also be used on functions
class Savings_Account final : public Account // public inheritance
{
	/*
	*  Public Inheritance:
	*  Has access to public nad protected
	*  Private is inherited but has no access
	*/

	/*
	*  Protected Inheritance:
	*  Public and Protected both become protected
	*  Private is inherited but has no access
	*  
	*  Protected is the same as private except when inheritance is involved
	*/

	/*
	*  Private Inheritance:
	*  Public and Protected both become private
	*  Private is inherited but has no access
	*/

	/*
	*  Derived classes does NOT inherit:
	*  Base class constructors/destructors
	*  Base class overloaded assignment operators
	*  Base class friend functions
	*/

public:
	double int_rate;
	void deposit(double amount);
	virtual void withdraw(double amount); 
	virtual void say_hello(); // no const here, redefinition, not overriden
	virtual void say_something() const override; // override ensures you don't have a redefinition
	
	Savings_Account();
	Savings_Account(double int_rate);
	Savings_Account(std::string name);
	~Savings_Account();

	Savings_Account(const Savings_Account& other);
	Savings_Account& operator=(const Savings_Account& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Savings_Account& account);
};

