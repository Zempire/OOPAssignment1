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
	//Displays an updated version of the board whenever it's called.

	char **getBoard();
	//Returns a pointer to the board. Useful for AI.

	void placeStone(int array[], char symbol);
	//Takes a point from player and adds their symbol to the board.

	bool isValid(int choice[]);
	//Checks to make sure that the position passed to itself is not already
	//taken and that it is within the bounds of the board.

	int checkBoard(int array[], char symbol);
	//Checks for a win condition on current row, column and diagonals.

private:
	const int M = 15;
	const int K = 5;
	char **board; // Declared as a double pointer for dynamic size allocation.

};

