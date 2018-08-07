/*
 * Gomoku.cpp
 *
 *  Created on: 2 Aug. 2018
 *      Author: Zempire
 */

#include <string>
#include <iostream>
#include <iomanip>
#include "MKGame.h"

using namespace std;

int main() {
	srand(time(NULL));
	cout << "WELCOME TO MK GAME!!!" << endl;
	do {
		int size, winCon;
		int choice = -1;
		cout << "\nPLEASE CHOOSE A BOARDSIZE AND WIN CONDITION:"<< endl;
		cout << "\nBOARDSIZE: ";
		cin >> size;
		cout << "WIN CONDITION: ";
		cin >> winCon;

		while (choice < 0 || choice > 3) {
			cout << "PLEASE CHOOSE A FORMAT FROM THE FOLLOWING:\n\n";
			cout << "1. HUMAN VS HUMAN.\n"
					"2. HUMAN VS COMPUTER.\n"
					"3. COMPUTER VS COMPUTER.\n";
			cout << "\nCHOICE: ";
			cin >> choice;
		}

		MKGame newGame(size,winCon, choice);
		newGame.play();
	} while(true);

	return 0;

}



