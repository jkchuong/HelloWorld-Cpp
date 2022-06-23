#pragma once
#include <iostream>

struct Movie
{
	enum Rating
	{
		G = 0,
		PG,
		PG13,
		R
	};

	std::string name;
	Rating rating;
	int watched;
	
	Movie(std::string name, Rating rating, int watched);   // constructor
	Movie(std::string name, Rating rating);
	Movie();                                  // delegate constructor
	Movie(const Movie& source);               // copy constructor
	Movie(Movie&& source) noexcept;           // move constructor
	~Movie();                                 // destructor
};

