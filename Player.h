#pragma once

class Player
{
private:
	char symbol;

public:
	Player(char _symbol) : symbol(_symbol) {}
	char getSymbol() { return symbol; }
};

