// Matthew Binshtok
// Minesweeper
// 2017

#include <iostream>
#include <cstdlib>
using namespace std;

/* Board class

The Board class represents the minesweeper board.
It wraps a two-dimensional array of integers,
which represent the existence of mines in nearby cells.
There is also a two dimensional array of booleans,
which represent whether a cell's contents should be displayed.

A mine, the unlucky user's downfall, is represented by the number 9.
I chose 9 because a cell that is not a mine can never hold the value 9,
as in the max case when it is surrounded entirely by mines, it holds the value 8.
Also, nine sounds like mine. :)

Public functions:
generate() -> generates a new minesweeper board within this object
output() -> outputs the current status of the board
click() -> simulates the user clicking on a given cell

There are also private helper functions, which are only called within these member functions.

*/

#ifndef _BOARD_H_
#define _BOARD_H_

class Board {
public:

    // enum for the desired difficulty of the game
    enum GameDifficulty { EASY, MEDIUM, HARD };

    // Coordinate struct
    // struct for a coordinate on the minesweeper board
    struct Coordinate {
        int x_coor;
        int y_coor;
        Coordinate( int x, int y ){
            x_coor = x;
            y_coor = y;
        }
    };

    // constructor
    // Board( Board::GameDifficulty chosenDifficulty = MEDIUM );
    Board( Board::Coordinate userClick, Board::GameDifficulty chosenDifficulty = MEDIUM );

    // Public API

    // generates a new minesweeper board
    void generate();
    // generates a new minesweeper board with given coordinate free of both a mine and hint
    void generate( Board::Coordinate userClick );

    // outputs the current status of the board
    void output();

    // simulates the user clicking on a given cell
    bool click( int xCoor, int yCoor );


private:

    // initializes 2D arrays to default
    void initializeMineField();
    void initializeTruthMatrix();

    // helper functions
    void populate( int numberOfMines, Board::Coordinate userClick );
    int getNumberOfMines( Board::GameDifficulty chosenDifficulty );
    void placeMine( Board::Coordinate userClick);
    bool affectsClickLocation( Board::Coordinate thisMine, Board::Coordinate userClick );
    void updateSurroundingCells( int mineXCoor, int mineYCoor );
    bool onBoard( int xCoor, int yCoor );
    bool isMine( int xCoor, int yCoor );
    void updateHint( int xCoor, int yCoor );
    int getRandomNumber( int max );

    // board dimensions
    int horizontalSize, verticalSize;

    // difficulty of this board
    GameDifficulty currentDifficulty;

    // minesweeper board
    int mineField[10][10];
    // values indicate if cell is shown to user
    bool truthVals[10][10];

};

#endif
