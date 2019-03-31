#include <iostream>
#include "amoebas.h"

using namespace std;

// An amoeba is born, named s
Amoeba::Amoeba(string s)
{
    myName = s;
    myParent = 0;
    myOlderSibling = 0;
    myOldestChild = 0;
    myYoungestChild = 0;
}

// Access functions
string Amoeba::Name()
{
    return myName;
}

Amoeba* Amoeba::Parent()
{
    return myParent;
}

void Amoeba::AddChild(Amoeba* newChild)
{
    // make child point to parent
    newChild->myParent = this;

    // check for parent having other children
    Amoeba* otherSibling = myYoungestChild;
    if (!otherSibling)
    {
        // the new amoeba is an only child
        myYoungestChild = newChild;   // make the parent's child
        myOldestChild = newChild;     // ptrs point to the new one
        newChild->myOlderSibling = 0; // no older sibling
    }
    else
    {
        // there are other kids; make this one the youngest
        myYoungestChild = newChild;              // no younger siblings,
        newChild->myOlderSibling = otherSibling; // but new kid now
    }                                            // has older siblings.
}

void Amoeba::PrintChildren() 
{
    // prints the names of the amoeba's children, one per line
    // we have an oddly linked structure which is not completely bi-directional
    // we have a link to the youngest child and each child has a link to a successively
    // older sibling
    // cout << "--- " + myName + "'s children ---" << endl;
    if (myYoungestChild != 0) { // if there is at least one child
        Amoeba* temp = myYoungestChild;
        while (temp != 0) {
            cout << temp->Name() << endl;
            temp = temp->myOlderSibling; // iterate through the link
        }
    }
}

void Amoeba::PrintGrandchildren()
{
    // prints the names of an amoeba's grandchildren, using PrintChildren()
    // cout << "--- " + myName + "'s grandchildren ---" << endl;
    if (myYoungestChild != 0) { // if there is at least one child
        Amoeba* tempChild = myYoungestChild;
        while (tempChild != 0) {
            tempChild->PrintChildren(); // print the children of this child, i.e. grandchildren
            tempChild = tempChild->myOlderSibling; // iterate through the link
        }
    }
}

static int generation = 0; // is this best place for this?

void Amoeba::PrintDescendants()
{
    // a depth first descent through the family tree, printing names and properly
    // tabbing for each generation
    int genTemp = 0; // temporary storage of the generation counter while descending

    // first print your name, then if there are children, descend
    if (generation != 0) {
        // only print the names of descendants
        PrintTabs(generation);
        PrintName();
    }

    genTemp = generation; // remember where we were before we started descending
    if (myYoungestChild != 0) {
        // recursive call on a child and then move laterally
        generation++;
        myYoungestChild->PrintDescendants();
    }

    generation = genTemp; // reset the generation counter
    if (myOlderSibling != 0 and generation != 0) {
        // we only want to move laterally on descendants
        myOlderSibling->PrintDescendants();
    }
    generation = 0; // reset the counter for the next call
}

void Amoeba::PrintName()
{
    cout << myName << endl;
}

void Amoeba::PrintTabs(int n) {
    // prints n tabs
    for (int i = 1; i < n; i++) {
        cout << "  ";
    }
}