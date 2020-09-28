#ifndef Turn_h
#define Turn_h

#include <iostream>

using namespace std;

class Turn {
	private:
		int turn;
		int pNumber;
		int aTile;
		int dNumber;
		char tileType;
		int fTile;
		
	public:
		Turn();
		Turn(int, int, int, int, char, int);
		void setTurn(int);
		void setPNum(int);
		void setATile(int);
		void setDNum(int);
		void setTileType(char);
		void setFTile(int);
		friend ostream & operator << (ostream &out, const Turn &t);
	
};


#endif

