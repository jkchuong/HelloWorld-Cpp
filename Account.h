#pragma once

#include "IllegalBalanceException.h"
#include <iostream>
#include<string>
#include <string_view>

class Account
{
private:
	static constexpr const std::string_view DEF_NAME = "Unnamed";
	static constexpr const double DEF_BALANCE = 0.0;

public:
	double balance;
	std::string name;
	void deposit(double amount);
	virtual void withdraw(double amount); // virtual for dynamic binding
	virtual void say_hello() const;
	virtual void say_something() const;

	Account();
	Account(double balance);
	Account(std::string name);
	//~Account(); // commented out as we now have virtual destructor

	// virtual destructor MUST be present when there are virtual functions
	// all derived classes will also have virtual distructor
	virtual ~Account(); 

	// Don't need special constructors since we don't have raw pointers
	// But here for learning purposes
	Account(const Account& other);

	Account& operator=(const Account& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Account& account);
};

