#include "Movie.h"

// Constructor
Movie::Movie(std::string name, Rating rating, int watched) : name{name}, rating{rating}, watched{watched}
{
	std::cout << "Constructor called: " << name << '\n';
}

// Delegate Constructor
Movie::Movie(std::string name, Rating rating) : Movie{ name, rating, 0 }
{
	std::cout << "Delagate Constructor called: " << name << '\n';
}

// Delegate Constructor
Movie::Movie() : Movie{ "", Rating::G, 0 }
{
	std::cout << "Delagate Constructor called: " << name << '\n';
}

// Copy Constructor
Movie::Movie(const Movie& source) : Movie{ source.name, source.rating, source.watched }
{
	std::cout << "Copy Constructor called: " << name << '\n';
}

// Move Constructor
Movie::Movie(Movie&& source) noexcept : Movie{source.name, source.rating, source.watched}
{
	std::cout << "Move Constructor called: " << name << '\n';
}

// Destructor
Movie::~Movie()
{
	std::cout << "Destructor called: " << name << '\n';
}