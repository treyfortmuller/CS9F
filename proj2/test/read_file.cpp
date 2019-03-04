// read contents of a file and print it to screen
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream> // for reading and write to files

using namespace std;

int main() {

	fstream input; // initialize the file stream object
	string filename = "file.txt";

	input.open(filename.c_str()); // open the file for reading
	// note string::c_str returns a pointer to an array with the string data

	// check to see if we can open the file
	if (input.fail()) {
		cout << "Could not open file!" << endl;
		exit(1);
	}

	string s;

	// getline takes an istream object and a string to extract the line to
	while (getline(input, s)) {
		// it is common, as used above, to use getline to extract a line of text
		// and also check that the stream has not terminated or there was no
		// errors in the extraction process.
		cout << s << endl;

	}

	return 0;
}

