#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include "ioutil.h"
#include "sudoku.h"
#include "SudokuBoard.h"

const int BOARD_N = 3;
const int BOARD_SIZE = BOARD_N * BOARD_N;

/*********
 * Notes *
 *********/

// In the comments above each function prototype you will find the set of strings
// that that function can print.  The function MUST NOT print anything if it is
// not present in those comments.  When you turn in your code, you can remove the
// strings from those comments, as well as this note.


/*******************************
 * Classes, Structs and Types *
 ******************************/

// If number is 0, the square is not occupied.
struct Square
{
    int number; // number is 0 if square is not occupied
    bool permanent; // true if permanent rather than user input
};

class SudokuBoard {
    
public:
	
	/*********************************************
	 * The following function is written For You *
	 *********************************************/
    
	// REQUIRES:  board has been loaded
	// MODIFIES:  nothing
	// EFFECTS:  prints the board
	void printBoard();
    
	/**************************************************
	 * Prototypes for Functions You Need to Implement *
	 **************************************************/
	
	// REQUIRES:  nothing
	// MODIFIES:  board (data member)
	// EFFECTS:   initializes ALL values within board to 0 and false
	SudokuBoard(); // class constructor
    
	// REQUIRES:  nothing
	// MODIFIES:  board (data member)
	// EFFECTS:   initializes ALL values within board to 0 and false
	void initBoard();
    
	// REQUIRES: nothing
	// MODIFIES: board (data member)
	// EFFECTS:  Gets a filename from the user, attempts to open that file,
	//           (Note:  you have a function that does the above)
	//           and fills out the board with appropriate values in every Square
	//           returns true if the file opened successfully and
	//           the board loaded successfully (see prompt on bottom)
	//           false otherwise (see prompt on bottom)
	//           first 9 rows are the permanent values
	//	PROMPTS:  "Board loaded successfully"
	//	          "File didn't read properly"
	bool loadBoard();
    
	// REQUIRES:  board has been loaded
	//            [x,y] is a position within the array
	//            value is within range for the board
	// MODIFIES:  nothing
	// EFFECTS:  if this is a valid move, return true
	//            otherwise return false
	//            checks for validity are done in the order of
	//              row, column, subgrid
	// PROMPTS:  "That value is in conflict in this row"
	//           "That value is in conflict in this column"
	//           "That value is in conflict in this subgrid"
	//           If the move is invalid for multiple reasons, list all reasons
	bool isValidMove(int x, int y, int value) const;
    
	// REQUIRES:  board has been loaded
	// MODIFIES:  board
	// EFFECTS:  gets a coordinate pair (you have a function that does this)
	//           and a value from the user and attempts to
	//           place it on the board
	//           check validity in the following order
	//	               "That location cannot be changed"
	//	               "Invalid number"
	//           If the move is valid,
	//                 change the matrix to reflect the player’s wishes
	// PROMPTS:	"That location cannot be changed"      (meaning permanent)
	//	        "Invalid number"
	void placeValue();
    
	// REQUIRES:  board has been loaded
	// MODIFIES:  board
	// EFFECTS:   gets a coordinate pair from the user (you have a function to do this)
	//            and attempts to delete it from the board
	// PROMPTS:  "That location cannot be changed"  (meaning permanent)
	void deleteValue();
    
	// REQUIRES:  board has been loaded
	// MODIFIES:  nothing
	// EFFECTS:   returns true if the board is full
	bool isFull() const;
    
	// REQUIRES: board has been loaded
	// MODIFIES: board
	// EFFECTS: Plays the game, returns when the user quits or wins
	//	        Reprint the board before asking for a move.
	//          Moves are case insensitive.
	//          On an invalid move/command: dump all input up to the '\n'
	//          Upon placing all the numbers, reprint the "winning" board
	//               following the congrats
	//  PROMPTS:  "Enter a move: "
	//	          "You did it - congrats!"
	void playGame();
    
private:
    
	// Sudoku board declaration
	Square board[BOARD_SIZE][BOARD_SIZE] = {{0, false}};
	
	// Number of board squares that are empty
    unsigned int emptySqrCount;
};

#endif
