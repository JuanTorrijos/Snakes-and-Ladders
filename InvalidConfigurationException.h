#ifndef InvalidConfigurationException_h
#define InvalidConfigurationException_h

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class InvalidConfigurationException: public exception {
	private:
		string paramName;
		int paramValue;
	
	public:
		InvalidConfigurationException(string, int);
		const char* what() const throw ();
	
};

#endif /* InvalidConfigurationException_h */

