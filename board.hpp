/**
 * @brief A 3x3 board class for tic-tac-toe.
 */

class Board
{
	private:
	    char *squares; // 3x3 board
	public:
	    Board();
	    ~Board();
	    void Place(int position, char player); // position is location in array
	    char Query(int position);
	    int CheckWin();
	    int CheckDraw();
	    void Show();
};
	    
	
