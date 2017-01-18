#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Board.h"

int main(){

    srand( time(0) ); // This line will ensure a randomized number within Board.
    Board* currentBoard = new Board();
    currentBoard->output();

}
