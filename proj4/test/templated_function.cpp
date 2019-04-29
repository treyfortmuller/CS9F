#include <iostream>
#include <string>

using namespace std;

// overloaded print functions for each type
void Print(int val) {
	cout << val << endl;
}

void Print(string word) {
	cout << word << endl;
}

// or we can write one templated function
// that can take any type that matches the interface that cout << works
template<typename T> // note you can also write this <classname T>
void PrintTemplate(T val) {
	cout << val << endl;
}

int main() {

    // we'll write a print function for several types, we'd have to overload it for each type
	Print(5); // calls one of the overloaded print functions for the right type
	Print("Hello!"); // calls the other overloaded print function

	PrintTemplate(10); // calls the templated function with the correct type
	PrintTemplate("Hello World!");
	// note we can also explicitly state the type in the function call
	PrintTemplate<int>(11);

    return 0;
}
