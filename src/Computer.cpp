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
	// X is my Symbol, O is enemy's symbol.
	string threatList[] = {" XXXX ", " OOOO", "OOOO ",
						   " OOO ", " XXX ", " XXX",
						   "XXX ", " OOO", "OOO ", " XX", "XX " };
	for (int i = 0; i < 11; i++)
		findThreat(boardCopy, threatList[i]);

	currentMove[0] = rand()%moveSpace;
	currentMove[1] = rand()%moveSpace;
}

void Computer::findThreat(char ** board, string threat) {
	    // Consider every point as starting point and search
    // given word


    for (int row = 0; row < moveSpace; row++) {
       for (int col = 0; col < moveSpace; col++) {
          if (searchThreat(board, row, col, threat))
             cout << "pattern found at " << row << ", " << col << endl;
       }
    }
}

bool Computer::searchThreat(char ** board, int row, int col, string threat)
{
	int x[] = {  0, -1, -1, -1, 0, 1, 1,  1 };
	int y[] = { -1, -1,  0,  1, 1, 1, 0, -1 };
	int length = threat.length();
    if (board[row][col] != threat[0]) {
    	return false;
    }

    // Search word in all 8 directions starting from (row,col)
    for (int dir = 0; dir < 8; dir++)
    {
        // Initialize starting point for current direction
        int k, rd = row + x[dir], cd = col + y[dir];

        // First character is already checked, match remaining
        // characters
        for (k = 1; k < length; k++)
        {
            // If out of bound break
            if (rd >= moveSpace || rd < 0 || cd >= moveSpace || cd < 0)
                break;

            // If not matched,  break
            if (board[rd][cd] != threat[k])
                break;

            //  Moving in particular direction
            rd += x[dir], cd += y[dir];
        }

        if (k == length)
            return true;
    }
    return false;
}
