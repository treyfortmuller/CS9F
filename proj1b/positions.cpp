#include "positions.h"
#include <iostream>
#include <cmath>

using namespace std;

const float PI = 3.14159;

// implementation of the Positions class
// Position: Consists of a radius expressed in meters and an angle expressed
// in radians.

// private:
//     float myRadius;
//     float myAngleInRadians;

Position::Position()
{
	// default constructor
	// radius = 1, angle = 0.
	myRadius = 1;
	myAngleInRadians = 0;
}

Position::Position(float r)
{
	// angle = 0.
	myRadius = r;
	myAngleInRadians = 0;
}

Position::Position(float r, float thetaInRadians)
{
	// TODO: add support for angles > 2PI and negative angles
	myRadius = r;
	myAngleInRadians = thetaInRadians;
}

void Position::SetAbsolutePosition(float r, float thetaInRadians)
{
	// Reinitialize this position.
	myRadius = r;
	myAngleInRadians = thetaInRadians;
}

void Position::IncrementPosition(float rChange, float angularDistChange)
{
	// Change this position, incrementing the radius by rChange and
	// incrementing the angle by angularDistChange/myRadius.
	// angularDistChange is expressed in meters.
	// One of the two arguments must be 0.
	// Negative radius values represent movement toward the statue.
	// Positive distance changes represent counterclockwise motion;
	// negative values are clockwise.
	
	// protect against the cat moving inside the statue
	myRadius += rChange;

	if (myRadius < 1) {
		myRadius = 1;
	}
	
	myAngleInRadians += (angularDistChange / myRadius);
}

void Position::Print() const
{
	// Print this position.
	// const keyword to forbid the compiler from allowing this function
	// to affect the object state
	cout << "Radius: " << myRadius << "\n";
	cout << "Angle (rad): " << myAngleInRadians << endl; 
}

bool Position::Sees(Position pos) const
{
	// Return true if someone at this position can see someone or
	// something at the argument position (i.e. the statue does
	// not block one's view), and return false otherwise.
	// The argument position must be at the statue.

	// TODO: why is pos.myAngleInRadians accessible 
	// shouldn't I need a getter function to get this private instance variables???
	// would it be better to have getter functions instead of this???
	if (myRadius * cos(myAngleInRadians - pos.myAngleInRadians) >= 1.0) {
		return true;
	} else {
		return false;
	}
}

bool Position::IsAtStatue() const
{
	// Return true if this position is at the base of the statue,
	// i.e. its radius is 1, and return false otherwise.
	if (myRadius == 1) {
		return true;
	} else {
		return false;
	}
}

bool Position::IsBetween(Position pos1, Position pos2) const
{
	// Return true if this position is between the first argument
	// position and the second.  Precondition: the counterclockwise
	// difference between the first and second argument positions
	// is less than pi radians, and the radii of all the positions
	// are the same.
	bool isBetween = false;

	float ccwDiff = pos2.myAngleInRadians - pos1.myAngleInRadians;
	
	if (ccwDiff <= PI && myRadius == pos1.myRadius == pos2.myRadius) {
		// precondition is satisfied
		// if cos (B - A) > cos (C - A), and cos (C - B) > cos (C - A) then angle B is between A and C
		if (cos(myAngleInRadians - pos1.myAngleInRadians) > cos(pos2.myAngleInRadians - pos1.myAngleInRadians) && cos(pos2.myAngleInRadians - myAngleInRadians) > cos(pos2.myAngleInRadians - pos1.myAngleInRadians)) {
			isBetween = true;
		}
	}
	return isBetween;
}