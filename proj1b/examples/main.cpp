// pass by reference example
// includes an example with const reference paramters

#include <iostream>
#include <string>
#include "example.h"

using namespace std;

void noChange(const string & big_param) {
	// const reference parameter won't be copied
	// but also wont be modified by the function
	cout << big_param.length() << endl;
}

int main() {

	Example instance; // an instance of the Example class is instantiated

	int num = 0;
	instance.change(num);

	cout << num << endl;

	string word = "Hello!";
	noChange(word);

	// some cool string concatination syntactical sugar
	string word1 = "hello";
	string word2 = " world";
	string phrase = word1 + word2;
	cout << phrase + "!" << endl;

	return 0;
}
