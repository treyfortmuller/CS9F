#include <stdlib.h> // I'm using GCC which needs this include for exit()
#include <vector>
#include <string>
#include <iostream> // needed to add this, for some reason it wasn't here already
using namespace std;

#include "positions.h"
#include "park.h"
#include "animals.h"

const int NUMANIMALS = 3;

// Set up the scene of animals.
Scene::Scene()
    : allAnimals(NUMANIMALS)
{
    string response1, response2;
    float r, thetaInRadians;
    int k;
    for (k = 0; k < NUMANIMALS; k++)
    {
        cout << "What kind of animal should be next? ";
        cin >> response1;
        cout << "What is its name? ";
        cin >> response2;
        cout << "What is its starting position?" << endl << "    radius = ";
        cin >> r;
        cout << "    angle in radians = ";
        cin >> thetaInRadians;
        Position coords(r, thetaInRadians);
        if (response1 == "mouse")
        {
            allAnimals[k] = new Mouse(response2, coords);
        }
        else if (response1 == "cat")
        {
            allAnimals[k] = new Cat(response2, coords);
        }
        else if (response1 == "person")
        {
            allAnimals[k] = new Person(response2, coords);
        }
        else
        {
            cout << "I don't know what that is." << endl;
            exit(1);
        }
    }
    // Define all the targets for the animals.
    for (k = 0; k < NUMANIMALS; k++)
    {
        cout << "Who is " << allAnimals[k]->myName << " chasing? ";
        cin >> response1;
        for (int k2 = 0; k2 < NUMANIMALS; k2++)
        {
            if (response1 == allAnimals[k2]->myName)
            {
                if (k2 == k)
                {
                    cout << allAnimals[k]->myName << " can't chase itself!" << endl;
                    exit(1);
                }
                else
                {
                    allAnimals[k]->myTarget = allAnimals[k2];
                    break;
                }
            }
        }
        if (allAnimals[k]->myTarget == 0)
        {
            cout << " not chasing anyone." << endl;
        }
    }
}

// Return the number of animals in the scene.
int Scene::Length()
{
    return allAnimals.size();
}

// Index the scene.
Animal*& Scene::operator[](int k)
{
    return allAnimals[k];
}

// Constructor (s is the animal's name,
// coords is its starting position).
Animal::Animal(string s, Position coords)
{
    myName = s;
    myPos = coords;
    myTarget = 0;
}

// Access functions.

string Animal::Name() const
{
    return myName;
}

Position Animal::Pos() const
{
    return myPos;
}
