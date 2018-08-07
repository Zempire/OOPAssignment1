/*
 * Board.cpp
 *
 *  Created on: 2 Aug. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Board.h"

using namespace std;

Board::Board() {
	board = new char * [M];
	for (int i = 0; i < M; i++)
		board[i] = new char[M];
	for (int row = 0; row < M; row++) {
		for (int col = 0; col < M; col++)
			board[row][col] = ' ';
	}
}

Board::Board(int size, int winCon)
	:M(size), K(winCon) {
	board = new char * [M];
		for (int i = 0; i < M; i++)
			board[i] = new char[M];
	for (int row = 0; row < M; row++) {
		for (int col = 0; col < M; col++)
			board[row][col] = ' ';
	}
}

Board::~Board() {
	cout<<"Removing Board." << endl;
	for (int i = 0; i < M; i++)
		delete[] board[i];
	delete[] board;
}

void Board::displayBoard() {
	// Print the Column Name.
	for (int colName = 0; colName < M; colName++) {
		cout << colName + 1;
		if (colName < M - 1)
			 cout << setw(4);
	}

	cout << endl;

	for (int row = 0; row < M; row++) {
		for (int col = 0; col < M; col++) {
			cout << board[row][col];
			if (col < M - 1)
				cout << "---";
		}
		cout << " " << row + 1 << endl; //Print the row name.
		if (row < M -1) {
			for (int i = M; i > 1; i--)
				cout << "|" << setw(4);

			cout << "|" << endl;
		}
	}
}

char ** Board::getBoard() {
	return board;
}
void Board::placeStone(int array[], char symbol) {
	board[array[0]][array[1]] = symbol;
}

bool Board::isValid(int choice[]) {
	int row = choice[0];
	int col = choice[1];

	if (row < 0 || row > M-1 || col < 0 || col > M)
		return false;
	else if (board[row][col] != ' ')
		return false;
	else
		return true;
}

int Board::checkBoard(int array[], char symbol) {
	int row = array[0];
	int col = array[1];
	cout << "(" << array[0] + 1 << "," << array[1] + 1 << ")\n";

	//CHECK THE COLUMN
	int rowPos = row;
	while (rowPos > 0 && board[rowPos-1][col] == symbol)
		rowPos--; //Traverses to first symbol in the chain.

	if (K <= (M-rowPos)){
		for (int i = 0; i < K; i++) {
			if (board[i + rowPos][col] != symbol)
				break;
			if (i == (K-1))
				return 1;
		}
	}

	//CHECK THE ROW
	int colPos = col;
	while (colPos > 0 && board[row][colPos-1] == symbol)
		colPos--; //Traverses to first symbol in the chain.

	for (int i = 0; i < K; i++) {
		if (board[row][i + colPos] != symbol)
			break;
		if (i == (K-1))
			return 1;
	}

	//CHECK FALLING DIAGONALS (row and col increase)
	rowPos = row;
	colPos = col;
	while (rowPos > 0 && colPos > 0 && board[rowPos-1][colPos-1] == symbol) {
		rowPos--;
		colPos--;
	}
	if (K <= (M-rowPos)){
		for (int i = 0; i < K; i++) {
			if (board[i + rowPos][i + colPos] != symbol)
				break;
			if (i == (K-1))
				return 1;
		}
	}
	//CHECK RISING DIAGONALS (row increases, col decreases)
	rowPos = row;
	colPos = col;
	while ((rowPos < M-1) && (colPos > 0) && board[rowPos+1][colPos-1] == symbol) {
		rowPos++;
		colPos--;
	}
	if ((rowPos + 1 >= K)){
		for (int i = 0; i < K; i++) {
			if (board[rowPos - i][i + colPos] != symbol)
				break;
			if (i == (K-1))
				return 1;
		}
	}

	return 0;
}



