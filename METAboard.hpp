/**
 * @brief A 3x3 metaboard class for tic-tac-toe (the large board).
 */

class MetaBoard
{
	private:
	    Board big_board[9];
	    Board wins;
	public:
	    MetaBoard();
	    ~MetaBoard();
	    void MetaPlace(int position, char player); // position is location in array
	    char MetaQuery(int position);
	    int MetaCheckWin();
	    int MetaCheckDraw();
	    void MetaShow();
};
	    
	
