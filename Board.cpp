#include <iostream>
#include <experimental/random>
using namespace std;

#include "Board.h";

#ifndef _BOARD_CPP_
#define _BOARD_CPP_

Board::Board( int givenHorizontalSize, int givenVerticalSize, GameDifficulty chosenDifficulty ){
    horizontalSize = givenHorizontalSize;
    verticalSize = givenVerticalSize;
    currentDifficulty = chosenDifficulty;
    mineField[verticalSize][horizontalSize] = { 0 }
    truthVals[verticalSize][horizontalSize] = { false };
    generate();

}

void Board::generate(){
    int numberOfMines = getNumberOfMines( chosenDifficulty );
    populate( numberOfMines );
}

int Board::getNumberOfMines( GameDifficulty chosenDifficulty ){
    int numberOfCells = horizontalSize * verticalSize;
    int divisor;
    switch ( chosenDifficulty ){
        case EASY:
        {   divisor = 15;
            break;  }
        case MEDIUM:
        {   divisor = 12;
            break;  }
        case HARD:
        {   divisor = 10;
            break;  }
    }
    int numberOfMines = numberOfCells / divisor;
    return numberOfMines;
}

void Board::populate( int numberOfMines ){
    while (numberOfMines != 0){
        placeMine();
        numberOfMines--;
    }
}

void Board::placeMine(){
    int mineXCoor = randint(0,horizontalSize);
    int mineYCoor = randint(0,verticalSize);
    if ( mineField[mineYCoor][mineXCoor] == 9 ){
        placeMine();
    } else {
        mineField[mineYCoor][mineXCoor] = 9;
    }
}

#endif
