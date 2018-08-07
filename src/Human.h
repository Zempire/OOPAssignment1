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
	Human(){}
	Human(const char sym)
			: Player(sym)
			  {
		cout << "I AM HUMAN\n";
		}
	void setMove();
};


