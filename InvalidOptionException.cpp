#include <stdio.h>
#include <string>
#include "InvalidOptionException.h"

#include <iostream>
using namespace std;

InvalidOptionException::InvalidOptionException(int c){
	cont = c;
}

const char* InvalidOptionException::what() const throw() {
	string impr;
	if(cont >= 5){
		impr = "Invalid menu choice exceeded";
	}
	else{
		impr = "Invalid option, please press C to continue next turn or E to end the game ";
	}
	
	cout << impr << endl;
    return &impr[0];
}

int InvalidOptionException::getCont(){
	return cont;
}