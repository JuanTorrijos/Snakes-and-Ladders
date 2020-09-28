//
//  MyGame.cpp
//  SerpientesEscaleras
//
//  Created by Rosa Guadalupe Paredes Juarez on 18/05/20.
//  Copyright © 2020 Rosa Paredes. All rights reserved.
//

#include <stdio.h>
#include "Dice.h"
#include "Board.h"
#include "MyGame.h"
#include "Turn.h"
#include "Player.h"
#include "InvalidOptionException.h"

using namespace std;

MyGame::MyGame(){
	nTiles = 30;
	nSnakes = 3;
	nLadders = 3;
	penalty = 3;
	reward = 3;
	nTurns = 30;
	nPlayers = 2;
	gType = 'M';
	turn = 1;
	dice = Dice();
}

MyGame::MyGame(int nt, int ns, int nl, int p, int r, int turnMax, int np, char gt) {
    turn = 1;
    dice = Dice();
	nTiles = nt;
	nSnakes = ns;
	nLadders = nl;
	penalty = p;
	reward = r;
	nTurns = turnMax;
	nPlayers = np;
	gType = gt;
}

void MyGame::start() {
	board = Board(nTiles, nSnakes, nLadders, penalty, reward);
	printTurn = Turn();
	int exCont = 0;
	for (int i=1 ; i<=nPlayers ; i++){
		players.push_back(Player(i, nTiles));
	}
	if(gType == 'M')
		cout << "Press C to continue next turn, or E to end the game:" << endl;
	char option = 'C';
	bool winner = false;
	int pInd = 0;

	while(option != 'E' && turn <= nTurns && winner == false ) {
		if(gType == 'A')
			option = 'C';
		else
			cin >> option;
		if(option == 'C') {
			printTurn.setTurn(turn);
			int number = dice.roll();
			printTurn.setPNum(players[pInd].getNumber());
			printTurn.setATile(players[pInd].getTile());
			printTurn.setDNum(number);
			players[pInd].setTile(players[pInd].getTile() + number);
			char c = board.getTile(players[pInd].getTile() - 1);
			printTurn.setTileType(c);
			if(c == 'S')
				players[pInd].setTile(players[pInd].getTile() - penalty);
			else if(c == 'L')
				players[pInd].setTile(players[pInd].getTile() + reward);
			printTurn.setFTile(players[pInd].getTile());
			cout << printTurn;
			if (players[pInd].getTile() >= nTiles){
				cout << "Player "<< to_string(pInd + 1)<< " is the winner!!!" << endl;
				winner = true;
			}
			pInd ++;
			if (pInd >= nPlayers){
				pInd = 0;
			}
			turn++;
		}
		else if (option != 'E') {
			exCont++;
			try{
				throw InvalidOptionException(exCont);
			}
			catch(InvalidOptionException &e){
				if (e.getCont() < 5){
					e.what();
				}
				else {
					e.what();
					option = 'E';
				}
			}
		}
	}
	
		cout << "-- GAME OVER --" << endl;
		
		if(turn >= nTurns)
			cout << "The maximum number of turns has been reached..." << endl;
		else if(players[pInd].getTile() >= nTiles)
			cout << "Player "<< to_string(pInd + 1)<< " is the winner!!!" << endl;
		else
			cout << "Thanks for playing!!!" << endl;
}

