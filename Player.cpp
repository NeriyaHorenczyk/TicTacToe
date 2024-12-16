#include "Player.h"

Player::Player(const std::string& _name, char _symbol) : name(_name), symbol(_symbol)
{
	if (symbol != 'X' && symbol != 'O')
	{
		throw std::invalid_argument("Invalid symbol. Must be either 'X' or 'O'.");
	}
}