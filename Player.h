#pragma once

#include <string>
#include<stdexcept>	

class Player
{
private:
	std::string symbol; // 'X' or 'O'
	std::string name;

public:
	Player(const std::string & _name, std::string _symbol);
	std::string getSymbol() const { return symbol; }
	std::string getName() const { return name; }
};

