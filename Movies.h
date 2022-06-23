#pragma once
#include "Movie.h";
#include <vector>
#include <string>
#include <iostream>

class Movies
{
private:
	std::vector<Movie> movies;
	const bool movie_exists(std::string name);

public:
	void create_movie(std::string name, Movie::Rating rating);
	void add_movie(std::string name, Movie::Rating rating, int watched);
	void watch_movie(std::string name);
	const void display_movies();
};

