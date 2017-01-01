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

    Board( int givenHorizontalSize, int givenVerticalSize, GameDifficulty chosenDifficulty = MEDIUM );
    void generate();
    void output();
    bool click( int xCoor, int yCoor );

private:

    // helper functions
    void populate();
    int getNumberOfMines( GameDifficulty chosenDifficulty );

    // board dimensions
    int horizontalSize, verticalSize;

    // difficulty
    enum GameDifficulty { EASY, MEDIUM, HARD };
    GameDifficulty currentDifficulty;

    // minesweeper board
    int mineField[][];
    // values represent whether cells are shown
    bool truthVals[][];

};

#include "Board.cpp";

#endif
