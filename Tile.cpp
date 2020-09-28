#include <iostream>
#include "Tile.h"

using namespace std;

Tile::Tile(){
	type = 'N';
	value = 0;
}

Tile::Tile(char t){
	type = t;
	value = 0;
}

char Tile::getType(){
	return type;
}

int Tile::getValue(){
	return 0;
}