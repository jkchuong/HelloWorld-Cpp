#include "Account.h"

Account::Account() : balance{ DEF_BALANCE }, name{ DEF_NAME }
{
	std::cout << "Base no-args constructor\n";
}

Account::Account(double balance) : balance{ balance }, name{ DEF_NAME }
{
	std::cout << "Base one-args constructor\n";

	if (balance < 0.0)
		throw IllegalBalanceException{};
}

Account::Account(std::string name) : balance{ DEF_BALANCE }, name{ name }
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

void Account::say_hello() const
{
	std::cout << "Account::say_hello\n";
}

void Account::say_something() const
{
	std::cout << "Account::say_something\n";
}