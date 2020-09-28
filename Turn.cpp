#include <iostream>
#include "Turn.h"

using namespace std;

Turn::Turn(){
	turn = 0;
	pNumber = 0;
	aTile = 0;
	dNumber = 0;
	tileType = '*';
	fTile = 0;
}

Turn::Turn(int tur, int pNum, int aT, int dNum, char tTy, int fT){
	turn = tur;
	pNumber = pNum;
	aTile = aT;
	dNumber = dNum;
	tileType = tTy;
	fTile = fT;
}

void Turn::setTurn(int t){
	turn = t;
}

void Turn::setPNum(int pN){
	pNumber = pN;
}

void Turn::setATile(int aT){
	aTile = aT;
}

void Turn::setDNum(int dN){
	dNumber = dN;
}

void Turn::setTileType(char tT){
	tileType = tT;
}

void Turn::setFTile(int fT){
	fTile = fT;
}

ostream & operator << (ostream &out, const Turn &t) 
{ 
	out << t.turn << " " << t.pNumber << " " << t.aTile << " " << t.dNumber 
		<< " " << t.tileType << " " << t.fTile << endl;
    return out; 
} 