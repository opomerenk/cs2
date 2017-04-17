#include "board.hpp"

/**
 * @brief Contains the game state.
 */

class Game
{
	private:
	    Board a;
	    int turn;
	public:
	    Game();
	    ~Game();
	    void Run();
};
