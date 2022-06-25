#include "Account.h"

Account::Account() : balance{0.0}, name{"An Account"}
{
	std::cout << "Base no-args constructor\n";
}

Account::Account(double balance) : balance{ balance }, name{ "An Account" }
{
	std::cout << "Base one-args constructor\n";
}

Account::Account(std::string name) : balance{ 0.0 }, name{ name }
{
	std::cout << "Base one-args name constructor\n";
}

Account::~Account()
{
	std::cout << "Base destructor\n";
}

Account::Account(const Account& other) : balance{ other.balance }, name{ other.name }
{
	std::cout << "Base copy constructor\n";
}

Account& Account::operator=(const Account& rhs)
{
	std::cout << "Base copy assignment\n";

	if (this != &rhs)
	{
		balance = rhs.balance;
		name = rhs.name;
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Account& account)
{
	os << "Account balance: " << account.balance;
	return os;
}

void Account::deposit(double amount)
{
	std::cout << "Account deposit called with " << amount << '\n';
	balance += amount;
}

void Account::withdraw(double amount)
{
	std::cout << "Account withdraw called with " << amount << '\n';

	if (balance >= amount)
		balance -= amount;
	else
		std::cout << "Not enough funds\n";
}