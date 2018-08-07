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

void Computer::setMove() {
	cout <<"\n\n" << symbol <<"'s MOVE: ";
	string * threatList;
	string  threatX[] = {" XXXX ", " XXXX", "XXXX ", " OOOO",
						 "OOOO "," OOO ", "X XX", "O OO",
						 " XXX ", " XXX", "XXX ", " OOO",
						 "OOO ", " XX", "XX ", " X", "X ", "O"};

	string  threatO[] = {" OOOO ", " OOOO", "OOOO ", " XXXX",
						 "XXXX ", " XXX ", "O OO", "X XX",
						 " OOO ", " OOO", "OOO ", " XXX",
						 "XXX ", " OO", "OO ", " O", "O ", "X"};

	symbol == 'X' ? threatList = threatX : threatList = threatO;
	cout << "\nSTEP?\n";
	cin.get();
	for (int i = 0; i < 18; i++){
	    for (int row = 0; row < moveSpace; row++) {
	       for (int col = 0; col < moveSpace; col++) {
	          if (searchThreat(boardCopy, row, col, threatList[i])){
	        	  cout << "THREAT at (" << row + 1 << "," << col + 1 << ")\n";
	        	  return;
	          }
	       }
	    }
	}
	currentMove[0] = rand()%moveSpace;
	currentMove[1] = rand()%moveSpace;


}

void Computer::findThreat(char ** board, string threat) {
    for (int row = 0; row < moveSpace; row++) {
       for (int col = 0; col < moveSpace; col++) {
          if (searchThreat(board, row, col, threat))
             break;
       }
    }
}

bool Computer::searchThreat(char ** board, int row, int col, string threat) {
	int x[] = {  0, -1, -1, -1, 0, 1, 1,  1 };//same, up, up, up, same, down, down, down
	int y[] = { -1, -1,  0,  1, 1, 1, 0, -1 };//left, left, same, right, right, right, same, left
	int length = threat.length();

		if (board[row][col] != threat[0]) {
			return false;
		}

    //Check each direction as x,y coordinate.
    for (int direction = 0; direction < 8; direction++)
    {
        // Initialize starting point for current direction
        int count;
		int rowPos = row + x[direction];
		int colPos = col + y[direction];

        // First character is already checked, match remaining
        // characters
        for (count = 1; count < length; count++)
        {
            // If out of bound break
            if (rowPos >= moveSpace || rowPos < 0 || colPos >= moveSpace || colPos < 0)
                break;

            // If not matched,  break
            if (board[rowPos][colPos] != threat[count])
                break;

            //  Moving in particular direction
            rowPos += x[direction], colPos += y[direction];
        }

        if (count == length) {
        	if (threat == "X XX" || threat == "O OO") {
        		currentMove[0] = row + x[direction];
        		currentMove[1] = col + y[direction];
        	}else if (board[row][col] == ' ') {
        		currentMove[0] = row;
        		currentMove[1] = col;
        	} else if (board[rowPos][colPos] == ' ') {
        		currentMove[0] = rowPos;
        		currentMove[1] = colPos;
        	} else {
        		currentMove[0] = rand()%moveSpace;
        		currentMove[1] = rand()%moveSpace;
        	}
        	return true;
        }
    }
    return false;
}
