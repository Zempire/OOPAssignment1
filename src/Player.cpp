/*
 * Player.cpp
 *
 *  Created on: 4 Aug. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Player.h"

Player::Player()
		: symbol(' '){
		cout << "I am a pointless player. Something went wrong :( ";
	}

Player::Player(const char sym)
		: symbol(sym) {

	}

char Player::getSymbol() {
		return symbol;
	}

int * Player::getMove() {
	return currentMove;
}
void Player::copyBoard(char ** board) {
	boardCopy = board;
}
void Player::setMove() {
	int row, col;
	cout << "\nPlayer " << symbol << "'s turn.\n";
	cout << "\nPlease choose a ROW followed by a COLUMN." << endl;
	row = validInt("ROW: ") - 1;
	col = validInt("COLUMN: ") - 1;
	currentMove[0] = row;
	currentMove[1] = col;
}

int Player::validInt(char const * line) {
	int choice;
	cout << line;
	cin >> choice;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Not an integer. Please try again." << endl;
		cout << line;
		cin >> choice;
	}

	return choice;
}

Player::~Player() {
	delete currentMove;
}





