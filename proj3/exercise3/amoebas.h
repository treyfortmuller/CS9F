#ifndef AMOEBA_H
#define AMOEBA_H

#include <string>

// we need this because the string type is part of the C++ standard library
// alternatively, we could pre-pend "std::" before each instance of "string"
using namespace std;

class Amoeba
{
public:
    Amoeba(string);           // birth of an amoeba
    string Name();            // returns your name
    Amoeba* Parent();         // returns your parent
    void AddChild(Amoeba*);   // add a baby amoeba to the family
    void PrintChildren();    // prints the names of children
    void PrintGrandchildren();    // prints the names of grandchildren
    void PrintDescendants();    // prints the names of all descendants
    void PrintName();        // print the name of the amoeba

private:
    string myName;            // this amoeba's name
    Amoeba* myParent;         // good old mom (or is it dad?)
    Amoeba* myOlderSibling;   // the next older brother/sister
    Amoeba* myYoungestChild;  // the youngest kid
    Amoeba* myOldestChild;    // the oldest kid
    void PrintTabs(int);
};

#endif
