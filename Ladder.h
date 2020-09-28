#ifndef Ladder_h
#define Ladder_h

#include "Tile.h"
using namespace std;

class Ladder:public Tile{
	protected:
		int reward;
		
	public:
		Ladder();
		Ladder(int);
		int getValue();
	
	
};

#endif 

