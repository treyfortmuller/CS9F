#include <iostream>

using namespace std;

int main() {

	// create an enumerated type with symbolic allowed values
	enum colors{red, orange, yellow, green, blue, purple};
	colors colorChoice = red;

	cout << colorChoice << endl; // prints 0

	// colors secondChoice = indigo; // an error, indigo is not an allowed value


	return 0;
}