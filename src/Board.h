/*
 * Board.h
 *
 *  Created on: 2 Aug. 2018
 *      Author: Zempire
 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Board {
public:
	Board();
	// Dynamically creates a board and fills with spaces. Default M and K.

	Board(int size, int winCon);
	//Allows adjustment of boards M and K.

	~Board();

	void displayBoard();

	char **getBoard();

	void placeStone(int array[], char symbol);

	bool isValid(int choice[]);
	//Checks to make sure that the position passed to itself is not already
	//taken and that it is within the bounds of the board.

	int checkBoard(int array[], char symbol);
	//Checks for a win condition on current row, column and diagonals.

private:
	int moveCount = 0;
	const int M = 15;
	const int K = 5;
	char **board; // Declared as a double pointer for dynamic size allocation.

};

