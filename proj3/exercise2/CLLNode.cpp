#include "CLLNode.h"
#include <iostream>
#include <cassert>
using namespace std;

/**
 * Return the successor of the given node.
 * Precondition: this != 0.
 */
CLLNode* CLLNode::next()
{
    assert(this != 0);
    assert(myPrevious != 0); // Consistency checks on circular list
    assert(myNext != 0);
    return myNext;
}

/**
 * Return the predecessor of the given node.
 * Precondition: this != 0.
 */
CLLNode* CLLNode::previous()
{
    assert(this != 0);
    assert(myPrevious != 0); // Consistency checks on circular list
    assert(myNext != 0);
    return myPrevious;
}

/**
 * Insert the node pointed to by ptr at the head of list and return a pointer
 * to new element.
 */
CLLNode* CLLNode::insert(CLLNode* ptr)
{
    // TODO: You fill this in
    return 0;
}

/**
 * Delete the first node from the list and return pointer to its successor, or
 * 0 if there was only one element in the list to start with.
 * Precondition: this != 0.
 */
CLLNode* CLLNode::remove()
{
    // TODO: You fill this in
    return 0;
}

/**
 * Print the list.
 */
void CLLNode::print() const
{
    if (this != 0)
    {
        const CLLNode* temp = this;
        do
        {
            cout << temp->myValue << " ";
            temp = temp->myNext;
        } while (temp != this);
    }
    cout << endl;
}

/**
 * Return true if the list contains exactly 1 element.
 */
bool CLLNode::lengthIsOne() const
{
    if (this == 0)
    {
        return false;
    }
    else if (this == myPrevious)
    {
        assert(myNext == myPrevious); // Consistency check on 1-elem list
        return true;
    }
    else if (this == myNext)
    {
        assert(false); // Failed consistency check!
    }
    else
    {
        return false;
    }
}
