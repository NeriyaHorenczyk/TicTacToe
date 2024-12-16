#include "TicTacToe.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    try
    {
        std::srand(std::time(nullptr)); // Seed for random generation

        TicTacToe game(4, 4); // Board 4x4, Win Length 4
        game.printBoard();

        bool winnerFound = false;
        int totalMoves = 0;
        int maxMoves = 4 * 4; // Maximum possible moves for a 4x4 board

        while (!winnerFound && totalMoves < maxMoves)
        {
            int move;
            do
            {
                move = std::rand() % 16 + 1; // Random move from 1 to 16
                try
                {
                    game.makeMove(move);
                    std::cout << "Move made at cell: " << move << "\n";
                    game.printBoard();
                    totalMoves++;
                    winnerFound = game.checkWin((move - 1) / 4, (move - 1) % 4); // Call a win-checking function
                    break;
                }
                catch (const std::exception& e)
                {
                    std::cerr << "Invalid move at cell " << move << ": " << e.what() << "\n";
                }
            } while (true);
        }

        if (winnerFound)
        {
            std::cout << "We have a winner!\n";
        }
        else
        {
            std::cout << "It's a draw!\n";
        }

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
