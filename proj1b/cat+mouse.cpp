#include "positions.h"
#include <iostream>
#include <cmath>

using namespace std;

float DegToRad(float deg)
{
	// helper function for converting angles in
	// degrees to angles in radians
	const float PI = 3.14159;
	return (deg * PI) / 180.0;
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

    cout << "Enter the Cat Radius (meters):\n";
    cin >> catRadius;

    cout << "Enter Cat Angle (deg):\n";
    cin >> catAngle;
    
    cout << "Enter Mouse Angle (deg):\n";
    cin >> mouseAngle;

    cat.SetAbsolutePosition(catRadius, DegToRad(catAngle));
    mouse.SetAbsolutePosition(1, DegToRad(mouseAngle));

    cout << "Printing mouse\n";
    mouse.Print();
    cout << endl;

    // cout << "Printing oldcat\n";
    // oldCat.Print();
    // cout << endl;

    cout << "Printing cat\n";
    cat.Print();
    cout << endl;

}

/**
 * You define the RunChase function.
 * Given initialized cat and mouse positions,
 * it should simulate the cat chasing the mouse, printing the
 * result of each movement of cat and mouse.  Either the cat will
 * catch the mouse, or 30 time units will go by and the cat will
 * give up.
 */
void RunChase(Position cat, Position mouse)
{
    bool mouseCaught = false;
    int loopCount = 0;

    Position oldCat = cat;

    cout << "Running chase..." << endl;
    while (!mouseCaught && loopCount < 30) {

        // cat moves in if it sees the mouse
        if (cat.Sees(mouse)) {
            cat.IncrementPosition(-1, 0);
        } else {
            cat.IncrementPosition(0, 1.25);
        }

        // cout << "Printing mouse\n";
        // mouse.Print();
        // cout << endl;

        // cout << "Printing oldcat\n";
        // oldCat.Print();
        // cout << endl;

        // cout << "Printing cat\n";
        // cat.Print();
        // cout << endl;

        // if the cat passes the mouse, its caught
        if (mouse.IsBetween(oldCat, cat)) {
            mouseCaught = true;
        } else {
            // mouse moves around statue
            mouse.IncrementPosition(0, 1);
        }

        // update the previous position of the cat
        oldCat = cat; 

        cout << "hitting loopCount\n";
        cout << mouseCaught << endl;    
        loopCount++;
    }

    // output the outcome of the chase
    cout << "Loop Count: " << loopCount << "\n";

    if (mouseCaught) {
        cout << "The cat ate the mouse!\n";
    } else {
        cout << "The cat got tired, mouse survives.\n";
    }
}

int main()
{
    Position cat, mouse;
    GetPositions(cat, mouse);
    // TODO: cat and mouse are not being updated by this function
    // might need to pass these by reference???
    RunChase(cat, mouse);

    return 0;
}
