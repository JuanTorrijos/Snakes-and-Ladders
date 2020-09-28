#include <stdio.h>
#include <string>
#include "InvalidConfigurationException.h"

#include <iostream>
using namespace std;

InvalidConfigurationException::InvalidConfigurationException(string nom, int val){
	paramName = nom;
	paramValue = val;
}	

const char* InvalidConfigurationException::what() const throw() {
	string impr = "Invalid " + paramName + " value " + to_string(paramValue);
	cout << impr << endl;
    return &impr[0];
}