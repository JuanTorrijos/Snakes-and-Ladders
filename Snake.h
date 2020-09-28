#ifndef Snake_h
#define Snake_h

#include <iostream>
#include "Tile.h"

using namespace std;

class Snake: public Tile {
	protected:
		int penalty;
		
	public:
		Snake();
		Snake(int);
		int getValue();
		
};



#endif 

