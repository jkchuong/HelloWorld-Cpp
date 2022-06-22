#pragma once

#include <iostream>
#include <vector>
#include <string>

class Player
{

	// Public - Open Access
	// Private - access only to members and friends
	// Protected - access only to inherited 

private:
	std::string name{"Default Name"}; // default values
	int health{0};
	int xp{0};

public:
	std::string get_name() const; // const -> method will not change const objects
	void set_name(std::string name);
	void talk(std::string text);
	void add_xp(int xp_to_add);
	int get_health() const;
	bool is_dead();

	// Constructor
	Player();
	Player(std::string name);
	Player(std::string name, int health);
	Player(std::string name, int health, int xp);

	// Destructor - will be called automatically
	~Player();

	// Copy Constructor
	Player(const Player& source);
};
