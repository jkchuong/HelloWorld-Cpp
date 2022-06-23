#include "Movies.h"

std::vector<Movie> movies{};

void Movies::create_movie(std::string name, Movie::Rating rating)
{
	if (movie_exists(name))
	{
		std::cout << name << " already exists!\n";
		return;
	}


	movies.push_back(Movie{ name, rating });
	std::cout << name << " added. You have " << movies.size() << " movies saved.\n";

	std::cout << "\n========================================================\n";
}

void Movies::add_movie(std::string name, Movie::Rating rating, int watched)
{
	if (movie_exists(name))
	{
		std::cout << name << " already exists!\n";
		return;
	}

	movies.push_back(Movie{ name, rating, watched });
	std::cout << name << " added. You have " << movies.size() << " movies saved.\n";
	std::cout << "\n========================================================\n";
}

void Movies::watch_movie(std::string name)
{
	for (Movie movie : movies)
	{
		if (movie.name == name)
		{
			movie.watched++;
			std::cout << "Watched " << movie.name << " " << movie.watched << " times\n";
			std::cout << "\n========================================================\n";
			break;
		}
	}

	std::cout << "Movie not in list - create or add movie first!\n";
	std::cout << "\n========================================================\n";
}

const void Movies::display_movies()
{
	if (movies.size() <= 0)
	{
		std::cout << "You haven't saved any movies!\n";
	}
	else
	{
		for (Movie movie : movies)
		{
			std::cout << movie.name << ", " << movie.rating << ", watched " << movie.watched << " times \n"; 
		}
	}
	std::cout << "\n========================================================\n";
}

const bool Movies::movie_exists(std::string name)
{
	for (Movie movie : movies)
	{
		if (movie.name == name)
		{
			return true;
		}
	}

	return false;
}