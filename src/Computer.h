/*
 * Computer.h
 *
 *  Created on: 3 Aug. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Player.h"

using namespace std;

class Computer: public Player {
public:
	Computer(){}
	//Default Constructor, shouldn't ever be called.

	Computer(const char sym, int boardSize);
	//Constructor we really want.

	void setMove();
	//Contains threatList and chooses move according to the list priority.

	bool searchThreat(char ** board, int row, int col, string threat);
	//Goes through all the threats checking in all possible directions
	//and returns true if threat is found.

private:
	int moveSpace = 10;
};


