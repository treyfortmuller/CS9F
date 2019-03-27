#ifndef _CLLNODE_H_
#define _CLLNODE_H_

#include <iostream>

class CLLNode
{
public:
    CLLNode(int k)
        : myValue(k)
        , myPrevious(this)
        , myNext(this)
    { /* Do nothing */
    }

    ~CLLNode()
    {
        std::cout << "Deleting node with value " << myValue << std::endl;
    }

    CLLNode* previous();
    // Return a ptr to the predecessor of the given node.

    CLLNode* next();
    // Return a ptr to the successor of the given node.

    CLLNode* insert(CLLNode* ptr);
    // Insert ptr node at head of list and return pointer to new element.

    CLLNode* remove();
    // Delete first node from the list; return pointer to its successor, or
    // 0.
    // Precondition: there is a node to delete.

    void print() const;

    bool lengthIsOne() const;
    // Return true if the list contains exactly 1 element.

private:
    int myValue;

    CLLNode* myPrevious;

    CLLNode* myNext;
};

#endif
