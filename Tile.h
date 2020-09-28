#ifndef Tile_h
#define Tile_h

#include <iostream>

using namespace std;

class Tile {
	protected:
		char type;
		int value;
	
	public:
		Tile();
		Tile(char);
		char getType();
		virtual int getValue();
};



#endif

