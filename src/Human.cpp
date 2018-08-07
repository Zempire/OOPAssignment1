/*
 * Human.cpp
 *
 *  Created on: 6 Aug. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Human.h"


using namespace std;

void Human::setMove() {
	int row, col;
	cout << "\nPlayer " << symbol << "'s turn.\n";
	cout << "\nPlease choose a ROW followed by a COLUMN." << endl;
	row = validInt("ROW: ") - 1;
	col = validInt("COLUMN: ") - 1;
	currentMove[0] = row;
	currentMove[1] = col;
}


