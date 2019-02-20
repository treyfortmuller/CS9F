#include "example.h"
#include <iostream>

using namespace std;

void Example::change(int & num) {
	// a function that takes a reference parameter
	// the ampersand can be written anywhere between the
	// type and the variable name
	num += 1;
}