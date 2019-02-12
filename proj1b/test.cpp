#include "positions.h"
#include <iostream>
#include <cmath>

using namespace std;

const float PI = 3.14159;

// prototypes
void testConstructors();
void testSetPose();
void testIncrement();
void testSees();
void testIsAtStatue();
void testIsBetween();

int main()
{
	testConstructors();
	// testSetPose();
	// testIncrement();
	// testSees();
	// testIsAtStatue();
	// testIsBetween();

	return 0;
}

void testConstructors()
{
	cout << "TEST CONSTRUCTORS\n\n";

	// default constructor
	Position test;
	
	cout << "DEFAULT\n";
	cout << "--- Expected ---\n";
	cout << "Radius: 1\n";
	cout << "Angle (rad): 0\n";
	cout << "--- Actual ---\n";
	test.Print();
	cout << "\n";

	// 1 argument constructor
	Position test1(2.5);

	cout << "1 ARGUMENT\n";
	cout << "--- Expected ---\n";
	cout << "Radius: 2.5\n";
	cout << "Angle (rad): 0\n";
	cout << "--- Actual ---\n";
	test1.Print();
	cout << "\n";

	// 2 argument constructor
	Position test2(2.5, PI/2);

	cout << "2 ARGUMENT\n";
	cout << "--- Expected ---\n";
	cout << "Radius: 2.5\n";
	cout << "Angle (rad): 1.57\n";
	cout << "--- Actual ---\n";
	test2.Print();
	cout << "\n";

	// 2 argument constructor with angle > 2*PI
	Position test3(2, 5*PI);

	cout << "2 ARGUMENT > 2*PI\n";
	cout << "--- Expected ---\n";
	cout << "Radius: 2\n";
	cout << "Angle (rad): 3.14\n";
	cout << "--- Actual ---\n";
	test3.Print();
	cout << "\n";
}

void testSetPose()
{

	cout << "TEST SET POSE\n";
	
	Position test;
	cout << "--- Original ---:\n";
	test.Print();
	
	test.SetAbsolutePosition(3.5, PI);

	cout << "--- Expected ---\n";
	cout << "Radius: 3.5\n";
	cout << "Angle (rad): 3.14\n";
	cout << "--- Actual ---\n";
	test.Print();
	cout << "\n";
}

void testIncrement()
{
	cout << "TEST INCREMENT POSITION\n";

	// test radial change
	Position test(2, 0);
	cout << "--- Original ---\n";
	test.Print();

	test.IncrementPosition(-1, 0);

	cout << "--- Expected (Radial) ---\n";
	cout << "Radius: 1\n";
	cout << "Angle (rad): 0\n";
	cout << "--- Actual ---\n";
	test.Print();
	cout << "\n";

	// test angular change
	Position test1(2, 0);
	cout << "--- Original ---\n";
	test1.Print();

	test1.IncrementPosition(0, PI);

	cout << "--- Expected (Angular) ---\n";
	cout << "Radius: 2\n";
	cout << "Angle (rad): 1.57\n";
	cout << "--- Actual ---\n";
	test1.Print();
	cout << "\n";

	// test arriving at statue
	Position test2(1.5, 0);
	cout << "--- Original ---\n";
	test2.Print();

	test2.IncrementPosition(-1, 0);

	cout << "--- Expected (Statue) ---\n";
	cout << "Radius: 1\n";
	cout << "Angle (rad): 0\n";
	cout << "--- Actual ---\n";
	test2.Print();
	cout << "\n";
}

void testSees()
{
	// a mouse at the statue, a cat at radius 2
	// they are at the same angle, mouse should be visible
	Position mouse, cat(2, 0);

	bool catSeeMouse = cat.Sees(mouse);

	cout << "--- Expected ---\n";
	cout << "true\n";

	cout << "--- Actual ---\n";
	cout << catSeeMouse << "\n";
	cout << "\n";

	// change cat position, mouse should not be visible
	cat.SetAbsolutePosition(2, PI);

	catSeeMouse = cat.Sees(mouse);

	cout << "--- Expected ---\n";
	cout << "false\n";

	cout << "--- Actual ---\n";
	cout << catSeeMouse << "\n";
	cout << "\n";	
}

void testIsAtStatue()
{
	// a mouse at the statue
	Position mouse, cat(2, 0);

	bool atStatue = mouse.IsAtStatue();

	cout << "--- Expected ---\n";
	cout << "true\n";

	cout << "--- Actual ---\n";
	cout << atStatue << "\n";
	cout << "\n";

	// cat at radius 2
	atStatue = cat.IsAtStatue();

	cout << "--- Expected ---\n";
	cout << "false\n";

	cout << "--- Actual ---\n";
	cout << atStatue << "\n";
	cout << "\n";	
}

void testIsBetween()
{

	// mouse's position is between the cat and its previous position 
	Position mouse(1, PI/4), cat(1, PI/2), catPrev(1, 0);
	
	bool mouseCaught = mouse.IsBetween(catPrev, cat);

	cout << "--- Expected ---\n";
	cout << "true\n";

	cout << "--- Actual ---\n";
	cout << mouseCaught << "\n";
	cout << "\n";

	// mouse's position is not between the cat and its previous position
	mouse.SetAbsolutePosition(1, PI);

	mouseCaught = mouse.IsBetween(catPrev, cat);

	cout << "--- Expected ---\n";
	cout << "false\n";

	cout << "--- Actual ---\n";
	cout << mouseCaught << "\n";
	cout << "\n";

	// cat goes full circle, mouse should not be caught
	cat.SetAbsolutePosition(1, 0);
	catPrev.SetAbsolutePosition(1, (3*PI/2));

	mouseCaught = mouse.IsBetween(catPrev, cat);

	cout << "--- Expected ---\n";
	cout << "false\n";

	cout << "--- Actual ---\n";
	cout << mouseCaught << "\n";
	cout << "\n";
}