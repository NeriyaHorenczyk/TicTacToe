#include "TicTacToe.h"

using std::cout;
using std::endl;
using std::setw;

TicTacToe::TicTacToe(int boardSize, int winRequire) 
	: N(boardSize), M(winRequire), player1("Player 1",'X'), player2("Player 2", 'O'), currentPlayer(&player1)
{
	if (N < 3 || M < 3 || M > N) // M must be between 3 and N
	{
		throw std::invalid_argument("Invalid board size or win requirement.");
	}

	board = std::vector<std::vector<char>>(N, std::vector<char>(N));
	int cellNumber = 1;
	for (auto& row : board)
	{
		for (auto& cell : row)
		{
			cell = cellNumber++ + '0';
		}
	}
	
}

void TicTacToe::printBoard()
{
	cout << "Current Board:\n";

	for (const auto& row : board)
	{
		for (const auto& cell : row)
		{
			cout << setw(3) << cell;
		}
		cout << endl;
	}
	cout << endl;
}

bool TicTacToe::checkWin(int row, int col)
{
	// Check row
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (board[row][i] == currentPlayer->getSymbol())
		{
			count++;
		}
		else
		{
			count = 0;
		}

		if (count == M)
		{
			return true;
		}
	}

	// Check column
	count = 0;
	for (int i = 0; i < N; i++)
	{
		if (board[i][col] == currentPlayer->getSymbol())
		{
			count++;
		}
		else
		{
			count = 0;
		}

		if (count == M)
		{
			return true;
		}
	}

	// Check diagonal
	count = 0;
	for (int i = 0; i < N; i++)
	{
		if (board[i][i] == currentPlayer->getSymbol())
		{
			count++;
		}
		else
		{
			count = 0;
		}

		if (count == M)
		{
			return true;
		}
	}

	// Check anti-diagonal
	count = 0;
	for (int i = 0; i < N; i++)
	{
		if (board[i][N - 1 - i] == currentPlayer->getSymbol())
		{
			count++;
		}
		else
		{
			count = 0;
		}

		if (count == M)
		{
			return true;
		}
	}

	return false;
}

void TicTacToe::makeMove(int row, int col)
{
	if (row < 0 || row >= N || col < 0 || col >= N)
	{
		throw std::invalid_argument("Invalid row or column.");
	}

	if (board[row][col] == player1.getSymbol() || board[row][col] == player2.getSymbol())
	{
		throw std::invalid_argument("Cell is already occupied.");
	}

	board[row][col] = currentPlayer->getSymbol();

	if (checkWin(row, col))
	{
		cout << "Player " << currentPlayer->getSymbol() << " wins!\n";
	}
	else
	{
		currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
	}
}


