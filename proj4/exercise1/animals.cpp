// You are to provide files animals.h and animals.cpp that define classes Mouse, Cat, and Person

#include <string>
#include <iostream>

#include "animals.h"
#include "park.h"
#include "positions.h"

using namespace std;

Mouse::Mouse(string s, Position p)
: Animal(s, p) {
	// do something to initialize Mouse
}

bool Mouse::Chase() {
	// Move the animal, and return true if it catches its target.
	myPos.IncrementPosition(0, 1);

	cout << "--- mouse position ---" << endl;
	myPos.Print();
	cout << endl;

	return false;
}

Cat::Cat(string s, Position p)
: Animal(s, p) {
	// do something to initialize Mouse
}

bool Cat::Chase() {
	// Move the animal, and return true if it catches its target.
	Position oldPos = myPos;

	if (myPos.Sees(myTarget->Pos())) {
		myPos.IncrementPosition(-1, 0);
	} else {
		myPos.IncrementPosition(0, 1.25);
	}

	cout << "--- cat position ---" << endl;
	myPos.Print();
	cout << endl;

	// check if we've captured the target
	if ((myTarget->Pos()).IsBetween(oldPos, myPos)) {
		cout << myName << " caught " << myTarget->Name() << endl;
		return true;
	}

	return false;
}

Person::Person(string s, Position p)
: Animal(s, p) {
	// do something to initialize Person
}

bool Person::Chase() {
	// Move the animal, and return true if it catches its target.
	if (!myPos.Sees(myTarget->Pos())) {
		myPos.IncrementPosition(0, 2);
		cout << myName << " saw " << myTarget->Name() << endl;
	}

	cout << "--- person position ---" << endl;
	myPos.Print();
	cout << endl;

	return false;
}
