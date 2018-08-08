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
	srand(time(NULL));//Seed for when Computer makes random move.
	int endChoice = -1;

	cout << "WELCOME TO MK GAME by Eugene Zem!!!" << endl;
	cout << "\nSuch fun times to be had ahead :D\n";
	string out = "....................................";

	for (int i = 0; i < 18; i++) {
		string spaces(i,' ');
		cout << spaces << out << spaces << endl;
		out = out.substr(1, out.size() - 2);
	}

	while (endChoice != 2) {
		int startChoice = -1;
		int size = -1;
		int winCon = -1;


		cout << "\nPLEASE CHOOSE A BOARDSIZE AND WIN CONDITION:"<< endl;

		while (size < 3 || size > 99) {
			cout << "\nBOARDSIZE: ";
			cin >> size;
		}

		while (winCon < 3 || winCon > size) {
			cout << "WIN CONDITION: ";
			cin >> winCon;
		}

		while (startChoice < 0 || startChoice > 3) {
			cout << "PLEASE CHOOSE A FORMAT FROM THE FOLLOWING:\n\n";
			cout << "1. HUMAN VS HUMAN.\n"
					"2. HUMAN VS COMPUTER.\n"
					"3. COMPUTER VS COMPUTER.\n";
			cout << "\nCHOICE: ";
			cin >> startChoice;
		}

		MKGame newGame(size, winCon, startChoice);
		newGame.play();
		cout << "1. PLAY AGAIN.\n"
				"2. EXIT GAME.\n\n"
				"CHOICE: ";

		cin >> endChoice;
	}
	cout << "\nTHANK YOU FOR PLAYING.\nSEE YOU LATER :)";
	return 0;
}



