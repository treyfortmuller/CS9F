#ifndef AMOEBA_H
#define AMOEBA_H

#include <string>

class Amoeba
{
public:
    Amoeba(string);           // birth of an amoeba
    string Name();            // returns your name
    Amoeba* Parent();         // returns your parent
    void AddChild(Amoeba*);   // add a baby amoeba to the family
private:
    string myName;            // this amoeba's name
    Amoeba* myParent;         // good old mom (or is it dad?)
    Amoeba* myOlderSibling;   // the next older brother/sister
    Amoeba* myYoungestChild;  // the youngest kid
    Amoeba* myOldestChild;    // the oldest kid
};

#endif
