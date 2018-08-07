/*
 * MKGame.cpp
 *
 *  Created on: 4 Aug. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "MKGame.h"

using namespace std;

void MKGame::play() {
	int current = 0;
	bool done = false;
	int status;

	while(!done) {
		gameBoard->displayBoard();
		//Give current player a copy of the board. Useful for Computer.
		players[current]->copyBoard(gameBoard->getBoard());
		players[current]->setMove();

		while(!gameBoard->isValid(players[current]->getMove())){
			cout << "Sorry that is not a valid move. Please try again.\n";
			players[current]->setMove();
		}

		gameBoard->placeStone(players[current]->getMove(), players[current]->getSymbol());
		status = gameBoard->checkBoard(players[current]->getMove(), players[current]->getSymbol());
		moveCount++;

		if(status == 1) {
			gameBoard->displayBoard();
			cout << "\nPLAYER " << players[current]->getSymbol() << " WINS!!!\n\n";
			cout << moveCount << " moves.\n";
			done = true;
		} else if (moveCount == boardFull) {
			gameBoard->displayBoard();
			cout << "\nGAME HAS ENDED IN A DRAW.\n\n";
			done = true;
		}

		current == 0 ? current = 1: current = 0;
	}
}
