// Matthew Binshtok
// Minesweeper
// 2017

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Board.h"

Board::Board( GameDifficulty chosenDifficulty ){
    currentDifficulty = chosenDifficulty;
    horizontalSize = 10;
    verticalSize = 10;
    initializeTruthMatrix();
    initializeMineField();
    generate();
}

// returns a random number from 0 to max
int Board::getRandomNumber( int max ){
	int randomNumber;
    randomNumber = rand()%max;
    // cout << randomNumber << "," << max << endl;
    return randomNumber;
}

// sets whole board to 0
void Board::initializeMineField(){
    for (int y = 0; y < 10; y++){
        for (int x = 0; x < 10; x++){
            mineField[y][x] = 0;
        }
    }
}

// sets all of truthVals to false
void Board::initializeTruthMatrix(){
    for (int y = 0; y < 10; y++){
        for (int x = 0; x < 10; x++){
            truthVals[y][x] = false;
        }
    }
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

void Board::generate(){
    int numberOfMines = getNumberOfMines( currentDifficulty );
    populate( numberOfMines );
}

void Board::populate( int numberOfMines ){
    while (numberOfMines != 0){
        placeMine();
        numberOfMines--;
    }
}

void Board::placeMine(){
    int mineXCoor = getRandomNumber( horizontalSize );
    int mineYCoor = getRandomNumber( verticalSize );
    if ( mineField[mineYCoor][mineXCoor] == 9 ){
        placeMine();
    } else {
        mineField[mineYCoor][mineXCoor] = 9;
        truthVals[mineYCoor][mineXCoor] = true;
        updateSurroundingCells( mineXCoor, mineYCoor );
    }
}

// this function updates the hints surroudning the mine
void Board::updateSurroundingCells( int mineXCoor, int mineYCoor ){
    // iterate through the surrounding cells and update the numbers
    for ( int y = -1; y < 2; y++ ){
        for ( int x = -1; x < 2; x++ ){
            int cellX = mineXCoor + x;
            int cellY = mineYCoor + y;
            // check that the cell is on the board
            if ( onBoard( cellX, cellY ) ){
                // make sure the cell is not a mine
                if ( !isMine( cellX, cellY ) ){
                    // update the hint
                    updateHint( cellX, cellY );
                }
            }
        }
    }
}

bool Board::onBoard( int xCoor, int yCoor ){
    return ( xCoor >= 0 && xCoor < horizontalSize && yCoor >= 0 && yCoor < verticalSize );
}

bool Board::isMine( int xCoor, int yCoor ){
    return mineField[yCoor][xCoor] == 9;
}

void Board::updateHint( int xCoor, int yCoor ){
    mineField[yCoor][xCoor]++;
    truthVals[yCoor][xCoor] = true;
}

void Board::output(){
    for (int yIndex = 0; yIndex < verticalSize; yIndex++ ){
        for (int xIndex = 0; xIndex < horizontalSize; xIndex++ ){
            if (truthVals[yIndex][xIndex]){
                cout << mineField[yIndex][xIndex] << " ";
            }
            else {
                cout << "X ";
            }
        }
        cout << endl;
    }
}

// returns false if the coordinate contains a mine
// otherwise, uncovers the relevant cells
/*bool Board::click( int xCoor, int yCoor ){

}*/
