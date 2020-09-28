#ifndef InvalidOptionException_h
#define InvalidOptionException_h

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class  InvalidOptionException: exception{
	private:
		int cont;
		
	public:
		InvalidOptionException(int);
		const char* what() const throw ();
		int getCont();
};

#endif

