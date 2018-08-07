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
	Computer(const char sym, int boardSize)
			: Player(sym)
			  {
		moveSpace = boardSize;
		cout << "I AM COMPUTER\n";
		}
	void setMove();
	void findThreat(char ** board, string threat);
	bool searchThreat(char ** board, int row, int col, string threat);

private:
	int moveSpace = 10;
};


