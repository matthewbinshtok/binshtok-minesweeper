#include <iostream>
using namespace std;

#include "Board.h";

#ifndef _BOARD_CPP_
#define _BOARD_CPP_

Board::Board( int givenHorizontalSize, int givenVerticalSize ){
    horizontalSize = givenHorizontalSize;
    verticalSize = givenVerticalSize;
    generate();
    truthVals[verticalSize][horizontalSize] = { false };
}

void Board::generate(){
    
}

#endif
