#include <iostream>
#include "Snake.h"
#include "Tile.h"

using namespace std;

Snake::Snake():Tile('S'){
	penalty= 3;
}

Snake::Snake(int p):Tile('S'){
	penalty=p;
}

int Snake::getValue(){
	return penalty;
}