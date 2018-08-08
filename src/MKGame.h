/*
 * MKGame.h
 *
 *  Created on: 3 Aug. 2018
 *      Author: Zempire
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Board.h"
#include "Player.h"
#include "Computer.h"
#include "Human.h"

using namespace std;

class MKGame {
public:
	MKGame(int m, int k, int choice)
		: M(m), K(k){
		gameBoard = new Board(m, k);
		switch(choice) {
		case 1:
			players[0] = new Human('O');
			players[1]= new Human('X');
			break;
		case 2:
			players[0] = new Human('O');
			players[1]= new Computer('X', M);
		break;
		case 3:
			players[0] = new Computer('O', M);
			players[1]= new Computer('X', M);
			break;
		default:
			break;
		}
	}

	void play();

	~MKGame(){
		delete gameBoard;
		delete * players;
	}

private:
	const int M = 15;
	const int K = 5;
	int moveCount = 0;
	const int boardFull = M * M;
	Board * gameBoard;
	Player * players[];

};



