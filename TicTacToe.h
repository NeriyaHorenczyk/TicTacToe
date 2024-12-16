#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <stdexcept>
#include "player.h"


class TicTacToe
{
private:
	int N;
	int M;
	std::vector<std::vector<std::string>> board;
	Player player1;
	Player player2;
	Player* currentPlayer;

public:
	TicTacToe(int N, int M);
	void printBoard();
	void makeMove(int cell);
	bool checkWin(int row, int col);

};

