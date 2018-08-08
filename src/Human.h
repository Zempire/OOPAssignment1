/*
 * Human.h
 *
 *  Created on: 3 Aug. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Player.h"

using namespace std;

class Human: public Player {
public:
	Human() {}
	//Default Constructor, shouldn't ever be called.

	Human(const char sym);
	//Constructor we really want.

	void setMove();
	//Takes input from user to make a move.
};


