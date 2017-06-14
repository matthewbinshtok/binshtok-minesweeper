// Matthew Binshtok
// Minesweeper
// 2017

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Board.h"

int main(){

    // Welcome Lines
    cout << "Minesweeper Game v1.0" << endl;
    cout << "by Matthew Binshtok" << endl << endl;

    // Create New Board
    srand( time(0) ); // This line will ensure randomized numbers within Board.
    Board::Coordinate firstClick = Board::Coordinate( 4,3 );
    Board currentBoard = Board(firstClick);
    currentBoard.output();
    
}
