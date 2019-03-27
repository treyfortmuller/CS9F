#ifndef LIST_H
#define LIST_H

class ListNode
{
public:
    ListNode(int k)
        : myValue(k)
        , myNext(0)
    { /* Do nothing */
    }

    ListNode(int k, ListNode* ptr)
        : myValue(k)
        , myNext(ptr)
    { /* Do nothing */
    }

    ~ListNode();
    // Delete the node and all nodes accessible through it;
    // precondition: this != 0.

    int first() const
    {
        return myValue;
    }
    // Return the value stored in the list node

    ListNode* rest() const
    {
        return myNext;
    }
    // Return the list consisting of the remaining elements

    void print() const;
    // Print the list

private:
    int myValue;

    ListNode* myNext;
};

#endif
