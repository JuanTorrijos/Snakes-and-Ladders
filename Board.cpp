//
//  Board.cpp
//  SerpientesEscaleras
//
//  Created by Rosa Guadalupe Paredes Juarez on 18/05/20.
//  Copyright © 2020 Rosa Paredes. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Board.h"
#include "Tile.h"
#include "Snake.h"
#include "Ladder.h"
using namespace std;

Board::Board(){
	nTiles = 30;
	nSnakes = 3;
	nLadders = 3;
	penalty = 3;
	reward = 3;
	create();
}

Board::Board(int nt, int ns, int nl, int p, int r){
	nTiles = nt;
	nSnakes = ns;
	nLadders = nl;
	penalty = p;
	reward = r;
	create();
}

void Board::create() {
    tiles = vector<Tile>(nTiles, 'N');
    int snakes = 0;
    int ladders = 0;
    while(snakes < nSnakes) {
        int index = (rand() % nTiles);
        if(tiles[index].getType() == 'N') {
            tiles[index] = Snake(penalty);
            snakes++;
        }
    }
    while(ladders < nLadders) {
        int index = (rand() % nTiles);
        if(tiles[index].getType() == 'N') {
            tiles[index] = Ladder(reward);
            ladders++;
        }
    }
}

string Board::draw(){
    string brd = "";
    for (Tile t : tiles) {
		char c = t.getType();
        brd += c;
        brd += " ";
    }
    return brd;
}

char Board::getTile(int index) {
    return tiles[index].getType();
}

int Board::getValue(int index){
	return tiles[index].getValue();
}