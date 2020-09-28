#include <iostream>
#include "Ladder.h"
#include "Tile.h"

using namespace std;

Ladder::Ladder():Tile('L'){
	reward=3;
}

Ladder::Ladder(int r):Tile('L'){
	reward=r;
}

int Ladder::getValue(){
	return reward;
}