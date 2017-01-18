// Matthew Binshtok
// Minesweeper
// 2017

#include <iostream>
using namespace std;

/* Board class

The Board class represents the minesweeper board.
It wraps a two-dimensional array of integers,
which represent the existence of mines in nearby cells.
There is also a two dimensional array of booleans,
which represent whether a cell's contents should be displayed.

A mine, the unlucky user's downfall, is represented by the number 9.
We choose 9 because a cell that is not a mine can never hold the value 9,
as in the max case when it is surrounded entirely by mines, it holds the value 8.
** a nine (9) --> a mine **

Member functions:
generate() -> generates a new minesweeper board
output() -> outputs the current status of the boards
click() -> simulates the user clicking on a given cell

There are also helper functions, which are only called with in these member functions.

Preconditions:
- Minimum board size is 8x8.

*/

#ifndef _BOARD_H_
#define _BOARD_H_

class Board {
public:

    enum GameDifficulty { EASY, MEDIUM, HARD };

    Board( Board::GameDifficulty chosenDifficulty = MEDIUM );
    void generate();
    void output();
    bool click( int xCoor, int yCoor );


private:

    // helper functions
    void populate( int numberOfMines );
    int getNumberOfMines( Board::GameDifficulty chosenDifficulty );
    void placeMine();
    void updateSurroundingCells( int mineXCoor, int mineYCoor );
    bool onBoard( int xCoor, int yCoor );
    bool isMine( int xCoor, int yCoor );
    void updateHint( int xCoor, int yCoor );
    int getRandomNumber( int max );

    // board dimensions
    int horizontalSize, verticalSize;

    // difficulty
    GameDifficulty currentDifficulty;

    // minesweeper board
    int mineField[10][10];
    // values represent whether cells are shown
    bool truthVals[10][10];

};

#include "Board.cpp"

#endif
