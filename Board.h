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

*/

#ifndef _BOARD_H_
#define _BOARD_H_

class Board {
public:

    Board( int givenHorizontalSize, int givenVerticalSize );
    void generate();
    void output();
    bool click( int xCoor, int yCoor );

private:

    // board dimensions
    int horizontalSize, verticalSize;

    // minesweeper board
    int mineField[][];
    // values represent whether cells are shown
    bool truthVals[][];

};

#include "Board.cpp";

#endif
