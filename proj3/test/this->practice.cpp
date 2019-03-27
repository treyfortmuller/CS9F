#include <iostream>
#include <string>

using namespace std;

class Fruit {

public:
	// the "this" keyword is only accessible inside member functions
	// "this" is a pointer to the current object instance
	string name;
	string color;

	int x; // example public member variable for accessing with ->

	Fruit(string name, string color) {
		// this is a pointer to the current object instance which is dereferenced using
		// the arrow operator and then we assign public members with the same name as the arguments
		// LHS refers to the public members whereas RHS refers to the arguments
		this->name = name;
		this->color = color;
	}

	void Print() {
		cout << "name is " + name << endl;
	}

};

int main() {
	// the arrow operator dereferences a pointer to an object so that you
	// can call functions on that object
	Fruit banana("banana", "yellow");
	
	banana.Print();

	Fruit* ptr = &banana;
	// we have a point to a fruit object, we cant call ptr.Print()
	// but we can dereference the pointer and call the method in one step with ->
	ptr->Print();

	// we can also access member variables using the reference+call/access operator (->)
	ptr->x = 0;
	cout << ptr->x << endl;

	return 0;
}