#include "Player.h"

std::string Player::get_name() const
{
	//name = "Jason"; // Error - can't change values in const method
	return name;
}

void Player::set_name(std::string name)
{
	(*this).name = name; // "this" refers to the address of the object
	// good way of comparing if two objects are the same 
}

void Player::talk(std::string text)
{
	std::cout << name << " says: " << text << '\n';
}

void Player::add_xp(int xp_to_add)
{
	xp += xp_to_add;
}

int Player::get_health() const
{
	return health;
}

bool Player::is_dead()
{
	return health <= 0;
}

Player::Player() // uses default values
{
	std::cout << "No args constructor called for " << name << '\n';
}

// Delegating Constructors -> calls another constructor, uses curly brackets
Player::Player(std::string name)
	: Player{ name, 0, 0 }
{
	std::cout << "One args constructor called for " << name << '\n';
}

// Constructor Initialization Lists
Player::Player(std::string name, int health)
	: name{ name }, health{ health }, xp{ 0 }
{
	std::cout << "Two args constructor called for " << name << '\n';
}

Player::Player(std::string name, int health, int xp)
{
	(*this).name = name;
	(*this).health = health;
	(*this).xp = xp;
	std::cout << "Three args constructor called for " << name << '\n';
}

// Destructor - will be called automatically
Player::~Player()
{
	std::cout << "Destructor called for " << name << '\n';
}

/*
*  Default copy constructor -> memberwise copy
*  Any pointers are copied, not what it points to (shallow copy)
*/

// Copy Constructor
Player::Player(const Player& source) : name{source.name}, health{source.health}, xp{source.xp}
{
	std::cout << "Copy constructor called for " << name << '\n';
}