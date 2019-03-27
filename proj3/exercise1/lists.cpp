#include "lists.h"
#include <iostream>
#include <cassert>
using namespace std;

/**
 * Delete the node and all nodes accessible through it.
 * Precondition: this != 0.
 */
ListNode::~ListNode()
{
    // this version is buggy
    cout << "Deleting node with value " << myValue << endl;
    // for (ListNode* p = this; p; p = p->myNext)
    // {
    //     delete p;
    // }

    // this is buggy for several reasons
    // it gets into an infinite loop because on the first pass through the for loop
    // we call "delete this" which just implicitly calls the destructor on the first element
    // of the linked list again.

    // its also bad because its trying to be recursive and a for loop at the same time, switching
    // to a purely recursive destructor is the cleanest and most transparent option

    if (myNext != 0) { // the base case
        delete myNext;
    }

    // the first node is already "deleted" by the original implicit call to the destructor
    // recursively descends through the linked list and hits the base case appropriately
}

/**
 * Print the list.
 */
void ListNode::print() const
{
    for (const ListNode* list = this; list; list = list->rest())
    {
        cout << list->first() << " ";
    }
    cout << endl;
}
