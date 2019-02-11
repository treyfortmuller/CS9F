#include "positions.h"
#include <iostream>
#include <cmath>
using namespace std;

float DegToRad(float deg)
{
	// helper function for converting angles in
	// degrees to angles in radians
	const float PI = 3.14159
	return (deg * pi) / 180.0
}

/**
 * You define the GetPositions function.
 * It should read legal cat and mouse positions from the user
 * and return the position values in its two arguments.
 */
void GetPositions(Position cat, Position mouse)
{
	// obtain intial cat and mouse positions from the
	// user and reinitialize the cat and mouse positions
	float mouseAngle;
	float catAngle;
	float catRadius;

    cout << "Enter the Cat Radius (meters):\n"
    cin >> catRadius;

    cout << "Enter Cat Angle (deg):\n"
    cin >> catAngle;
    
    cout << "Enter Mouse Angle (deg):\n"
    cin >> mouseAngle;

    cat.SetAbsolutePosition(catRadius, DegToRad(catAngle))
    mouse.SetAbsolutePosition(1, DegToRad(mouseAngle))

}

/**
 * You define the RunChase function.
 * Given initialized cat and mouse positions,
 * it should simulate the cat chasing the mouse, printing the
 * result of each movement of cat and mouse.  Either the cat will
 * catch the mouse, or 30 time units will go by and the cat will
 * give up.
 */
void RunChase(/* TODO: Your code here */)
{
    // TODO: Your code here
}

int main()
{
    Position cat, mouse;
    GetPositions(cat, mouse);
    RunChase(cat, mouse);

    return 0;
}
