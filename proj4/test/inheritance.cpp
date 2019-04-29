#include <iostream>
#include <string>

using namespace std;

class Entity {
public:
	int X, Y;

	// constructor for the base class
	Entity(int new_x, int new_y) {
		X = new_x;
		Y = new_y;
	}

	void PrintPosition() {
		cout << "X: " << X << endl;
		cout << "Y: " << Y << endl;
	}
};

// an example of syntax for "public inheritance" is below
class Person : public Entity { // class person inherits from class Entity
// we already have acess to all of entities public data and methods
public:
	string name;

	// we must use "constructor chaining" to properly use the constructor of a subclass
	// you throw the base class's constructor in the initializer list of the subclass.
	Person(string new_name)
	: Entity(0, 0) 
	{
		name = new_name;
	}

	void PrintName() {
		cout << name  << endl;
	}
};

int main() {

	Entity thing(2, 3);
	thing.PrintPosition();

	Person trey("Trey");

	// trey.PrintName();
	trey.X = 1;
	trey.Y = 2;
	trey.PrintPosition();

	return 0;
}