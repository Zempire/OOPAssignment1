
/*
 * Computer.cpp
 *
 *  Created on: 6 Aug. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Computer.h"


using namespace std;

Computer::Computer(const char sym, int boardSize) : Player(sym) {
	moveSpace = boardSize;
}

void Computer::setMove() {
	cout <<"\n\n" << symbol <<"'s MOVE: ";
	string * threatList;
	string  threatX[] = {" XXXX", " OOOO", "  XXX ", "  OOO ", " X XX ", " O OO ", "  XXX", "  OOO", " XX", "X X", " OO","O O", " X", " O"};

	string  threatO[] = {" OOOO", " XXXX", "  OOO ", "  XXX ", " O OO ", " X XX ", "  OOO", "  XXX", " OO", "O O", " XX", "X X", " O", " X"};

	symbol == 'X' ? threatList = threatX : threatList = threatO;
	cin.get();
	int direction = rand()%2;
	for (int i = 0; i < 14; i++) { // 14 is the length of threatList.
		switch(direction) {
		case 0:
			for (int row = 0; row < moveSpace; row++)
			   for (int col = 0; col < moveSpace; col++)
				  if (searchThreat(boardCopy, row, col, threatList[i]))
					  return;
			break;
		case 1:
			for (int row = moveSpace - 1; row >= 0; row--)
			   for (int col = moveSpace - 1; col >= 0; col--)
				  if (searchThreat(boardCopy, row, col, threatList[i]))
					  return;
			break;
		}
	}


	currentMove[0] = moveSpace/2;
	currentMove[1] = moveSpace/2;
}

bool Computer::searchThreat(char ** board, int row, int col, string threat) {
	// Control arrays for testing all directions.
	int x[] = {  0, -1, -1, -1, 0, 1, 1,  1 };//same, up, up, up, same, down, down, down
	int y[] = { -1, -1,  0,  1, 1, 1, 0, -1 };//left, left, same, right, right, right, same, left

	int length = threat.length();

		if (board[row][col] != threat[0]) {
			return false;
		}

    //Check each direction as x,y coordinate.
    for (int direction = 0; direction < 8; direction++) {
        int count;
		int rowPos = row + x[direction];
		int colPos = col + y[direction];

        for (count = 1; count < length; count++) {

        	if (rowPos >= moveSpace || rowPos < 0 || colPos >= moveSpace || colPos < 0)
                break; //Tests we are still on the board.

            if (board[rowPos][colPos] != threat[count])
                break; //Tests if the pattern is still possible

            rowPos += x[direction];
            colPos += y[direction];
        }

        if (count == length) {
        	if (threat == " X XX " || threat == " O OO ") {
        		currentMove[0] = row + (x[direction] * 2);
        		currentMove[1] = col + (y[direction] * 2);
        	}else if (threat == "  XXX" || threat == "  OOO") {
        		currentMove[0] = row + x[direction];
        		currentMove[1] = col + y[direction];
        	}else if (threat == "  XXX " || threat == "  OOO ") {
        		currentMove[0] = row + x[direction];
        		currentMove[1] = col + y[direction];
        	}else if (threat == "X X" || threat == "O O") {
        		currentMove[0] = row + x[direction];
        		currentMove[1] = col + y[direction];
        	}else if (board[row][col] == ' ') {
        		currentMove[0] = row;
        		currentMove[1] = col;
        	} else {
        		currentMove[0] = rand()%moveSpace;
        		currentMove[1] = rand()%moveSpace;
        	}
        	return true;
        }
    }
    return false;
}
