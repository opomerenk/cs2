#include "board.hpp"
#include <iostream>

/**
 * @brief Constructs an empty tic-tac-toe board with each square labeled
 * with a number 1-9.
 */

Board::Board()
{
	squares = new char[9];
	// Fill board with values.
	squares[0] = {'1'};
	squares[1] = {'2'};
	squares[2] = {'3'};
	squares[3] = {'4'};
	squares[4] = {'5'};
	squares[5] = {'6'};
	squares[6] = {'7'};
	squares[7] = {'8'};
	squares[8] = {'9'};
}

/**
 * @brief Deconstructs a tic-tac-toe board.
 */
 
Board::~Board()
{
	 delete[] squares;
}

/**
 * @brief Puts an X or O on the board at a desired position.
 */
 
void Board::Place(int position, char player)
{
	squares[position] = player;
}

/**
 * @brief Returns the square state at a given position.
 */

char Board::Query(int position)
{
	return squares[position];
}

/**
 * @brief Prints the tic-tac-toe board to the terminal.
 */

void Board::Show()
{
	int i;
	std::cout << "-------" << std::endl;
	for (i = 0; i < 3; i++)
	{
		std::cout << "|" << Query(i);
	}
	std::cout << "|" << std::endl << "-------" << std::endl;
	for (i = 3; i < 6; i++)
	{
		std::cout << "|" << Query(i);
	}
	std::cout << "|" << std::endl << "-------" << std::endl;
	for (i = 6; i < 9; i++)
	{
		std::cout << "|" << Query(i);
	}
	std::cout << "|" << std::endl << "-------" << std::endl;
}

/**
 * @brief Returns the player who won the game, if any. Returns 1 if player
 * one (X's) won, 2 if player two (O's) won, and 0 if nobody won.
 */

int Board::CheckWin()
{
	//Check all possible cases of wins: vertical, horizontal, and diagonal.
	if ((squares[0] == squares[1]) && (squares[0] == squares[2]) && (squares[0] != '.')) 
	{
		if (squares[0] == 'X')
		{
			return 1;
		}
		return 2;
	}
	else if ((squares[3] == squares[4]) && (squares[3] == squares[5]) && (squares[3] != '.'))
	{
		if (squares[3] == 'X')
		{
			return 1;
		}
		return 2;
	}
	else if ((squares[6] == squares[7]) && (squares[6] == squares[8]) && (squares[6] != '.'))
	{
		if (squares[6] == 'X')
		{
			return 1;
		}
		return 2;
	}
	else if ((squares[0] == squares[3]) && (squares[0] == squares[6]) && (squares[0] != '.'))
	{
		if (squares[0] == 'X')
		{
			return 1;
		}
		return 2;
	}
	else if ((squares[1] == squares[4]) && (squares[1] == squares[7]) && (squares[1] != '.'))
	{
		if (squares[1] == 'X')
		{
			return 1;
		}
		return 2;
	}
	else if ((squares[2] == squares[5]) && (squares[2] == squares[8]) && (squares[2] != '.'))
	{
		if (squares[2] == 'X')
		{
			return 1;
		}
		return 2;
	}
	else if ((squares[0] == squares[4]) && (squares[0] == squares[8]) && (squares[0] != '.'))
	{
		if (squares[0] == 'X')
		{
			return 1;
		}
		return 2;
	}
	else if ((squares[2] == squares[4]) && (squares[0] == squares[7]) && (squares[2] != '.'))
	{
		if (squares[2] == 'X')
		{
			return 1;
		}
		return 2;
	}
	// Return 0 if no win was achieved.
    return 0;
}

/**
 * @brief Checks to see if a draw was achieved. Returns 0 if no, 1 if yes.
 */

int Board::CheckDraw()
{
	int i;
	for (i = 0; i < 9; i++)
	{
		//If board is not filled, no draw occurred. Check to see if
		//there are any squares on the board with neither an X nor an O.
		if ((squares[i] != 'X') && (squares[i] != 'O'))
		{
			return 0;
		}
	}
	//No win and a full board indicates a draw.
	return 1;
}
	
	
	
	
		
		
