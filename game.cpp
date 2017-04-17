#include "game.hpp"
#include <iostream>


/**
 * @brief Contructs a tic-tac-toe game.
 */

Game::Game()
{
	Board a;
	turn = 1; //This will toggle back and forth between 1 and 2 during gameplay
}

/**
 * @brief Deconstructs the game.
 */

Game::~Game()
{
}
	
/**
 * @brief Runs the game.
 */

void Game::Run()
{
	int position;
	while (1)
	{
		//First, show the board and check to see if anyone won or drew the game
		a.Show();
		if (a.CheckWin() == 1)
	    {
			std::cout << "Player 1 wins!" << std::endl;
			break;
		}
	    else if (a.CheckWin() == 2)
		{
			std::cout << "Player 2 wins!" << std::endl;
			break;
		}
	    else if (a.CheckDraw() == 1)
		{
			std::cout << "Draw!" << std::endl;
			break;
		}
		std::cout << "Player " << turn << ", enter your move: ";
		std::cin >> position;
		position -= 1; //Subtract one to account for array positions
					   //being from 0-8 rather than from 1-9	
		if (turn == 1)
		{
			a.Place(position, 'X');
			turn = 2;
		}
		else
		{
			a.Place(position, 'O');
			turn = 1;
		}
    }
}
		
		
