#include "Savings_Account.h"


Savings_Account::Savings_Account() : int_rate{3.0}
{
	std::cout << "Derived no-args constructor\n";
}

Savings_Account::Savings_Account(double int_rate) : int_rate{int_rate}
{
	std::cout << "Derived one-args constructor\n";
}

// Calling base constructor with string paramter
Savings_Account::Savings_Account(std::string name) : Account{ name }, int_rate{3.0}
{
	std::cout << "Dervied one-args name constructor\n";
}

Savings_Account::~Savings_Account()
{
	std::cout << "Derived destructor\n";
}

// Using base class "slices" the base part and leaves the derived part
Savings_Account::Savings_Account(const Savings_Account& other) : Account(other), int_rate{other.int_rate}
{
	std::cout << "Derived copy constructor\n";
}

Savings_Account& Savings_Account::operator=(const Savings_Account& rhs)
{
	std::cout << "Derived copy assignment\n";

	if (this != &rhs)
	{
		Account::operator=(rhs); // Assign the base class part
		int_rate = rhs.int_rate; // Assign derived part
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Savings_Account& account)
{
	os << "Savings account balance: " << account.balance << " Interest rate: " << account.int_rate;
	return os;
}


void Savings_Account::deposit(double amount)
{
	std::cout << "Savings Account deposit called with " << amount << '\n';

	amount = amount + (amount * (int_rate / 100));
	Account::deposit(amount);
}

//void Savings_Account::withdraw(double amount)
//{
//	std::cout << "Savings Account withdraw called with " << amount << '\n';
//}