#pragma once

#include <exception>

class IllegalBalanceException : public std::exception
{
public:
	IllegalBalanceException() noexcept = default;
	~IllegalBalanceException() = default;

	virtual const char* what() const noexcept
	{
		return "Illegal balance exception";
	}
};

class IllegalFundsException : public std::exception
{
public:
	IllegalFundsException() noexcept = default;
	~IllegalFundsException() = default;

	virtual const char* what() const noexcept
	{
		return "Illegal funds exception";
	}
};