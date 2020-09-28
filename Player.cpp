//
//  Player.cpp
//  SerpientesEscaleras
//
//  Created by Rosa Guadalupe Paredes Juarez on 18/05/20.
//  Copyright © 2020 Rosa Paredes. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Player.h"

Player::Player() {
    number = 1;
    tile = 1;
	nTiles = 30;
}

Player::Player(int n, int nt) {
    number = n;
    tile = 1;
	nTiles = nt;
}

string Player::draw() {
    return to_string(number) + " " + to_string(tile);
}

void Player::setTile(int t) {
    if(t < 1)
        tile = 1;
    else if(t > nTiles)
        tile = nTiles;
    else
        tile = t;
}

int Player::getTile() {
    return tile;
}

int Player::getNumber(){
	return number;
}