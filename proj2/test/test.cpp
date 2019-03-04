#include <cstdlib> // for the exit function
#include <string>
#include <iostream> // standard io stream class
#include <sstream> // string stream class

using namespace std;

int main()
{

	string s;
	string word;
	// int i;

	// if (cin >> s >> i) { // hello 1
	// 	cout << "done\n";
	// 	exit(0);
	// } else { // 1 hello
	// 	cout << "not done\n";
	// 	exit(1);
	// }

	// cout << "Input some string...\n";
	// // to grab an individual word (separated by white spaces), use the extraction operator.
	// cin >> s;
	// cout << "You said: " << s << endl;

	// cout << "Input some more strings...\n";
	// // to grab a line of strings (separated by a delimiter '\n' by default), use getline()
	// getline(cin, s); // takes an input string stream (cin, ifstream, isstream, etc.)	
	// cout << "You said: " << s << endl;

	// grab a line of text and then parse it word by word using a string stream
	cout << "Enter a line of text!" << endl;
	getline(cin, s);
	istringstream input(s); // initialize a string stream bound to the string s
	
	int counter = 0;
	if (input >> word) {
		continue;
	} else

	if (counter == 0) {
		cerr << "NO WORDS" << endl;
	} else {
		cout << "There were " << counter << " words in the line." << endl;
	}

	return 0;

}