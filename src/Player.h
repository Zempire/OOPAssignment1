/*
 * Player.h
 *
 *  Created on: 3 Aug. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <iomanip>
#include <string>
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
public:
	Player();

	Player(const char sym);

	char getSymbol();
	//Returns the symbol associated with this player.

	int * getMove();
	//Returns currentMove array.
	void copyBoard(char ** board);
	//Copies board into local memory.

	virtual void setMove();
	//Updates currentMove based on the players input.

	virtual int validInt(char const * line);
	//Makes sure that the player actually enters an integer and not some
	//other character that may crash the game.

	virtual ~Player();

protected:
	const char symbol;
	int * currentMove = new int[2];
	char ** boardCopy = NULL;
};
#endif


