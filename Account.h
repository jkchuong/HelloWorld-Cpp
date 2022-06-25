#pragma once

#include <iostream>
#include<string>

class Account
{
public:
	double balance;
	std::string name;
	void deposit(double amount);
	void withdraw(double amount);

	Account();
	Account(double balance);
	Account(std::string name);
	~Account();

	// Don't need special constructors since we don't have raw pointers
	// But here for learning purposes
	Account(const Account& other);

	Account& operator=(const Account& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Account& account);
};

