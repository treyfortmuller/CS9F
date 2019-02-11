#include <iostream>
#include <cmath>

using namespace std;

// implementation of the Positions class
// Position: Consists of a radius expressed in meters and an angle expressed
// in radians.

// private:
//     float myRadius;
//     float myAngleInRadians;

Position::Position();
// radius = 1, angle = 0.

Position::Position(float r);
// angle = 0.

Position::Position(float r, float thetaInRadians);

void Position::SetAbsolutePosition(float r, float thetaInRadians);
// Reinitialize this position.

void Position::IncrementPosition(float rChange, float angularDistChange);
// Change this position, incrementing the radius by rChange and
// incrementing the angle by angularDistChange/myRadius.
// angularDistChange is expressed in meters.
// One of the two arguments must be 0.
// Negative radius values represent movement toward the statue.
// Positive distance changes represent counterclockwise motion;
// negative values are clockwise.

// TODO: what's with the const?
// void Position::Print() const;
// // Print this position.

void Position::Print()
{
	// Print this position.
	cout << "Radius: " << myRadius << "\n";
	cout << "Angle (rad): " << myAngleInRadians << endl; 
}

bool Position::Sees(Position pos) const;
// Return true if someone at this position can see someone or
// something at the argument position (i.e. the statue does
// not block one's view), and return false otherwise.
// The argument position must be at the statue.

bool Position::IsAtStatue() const;
// Return true if this position is at the base of the statue,
// i.e. its radius is 1, and return false otherwise.

bool Position::IsBetween(Position pos1, Position pos2) const;
// Return true if this position is between the first argument
// position and the second.  Precondition: the counterclockwise
// difference between the first and second argument positions
// is less than pi radians, and the radii of all the positions
// are the same.