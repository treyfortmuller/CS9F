#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <cassert>

// prototypes
template <class NODETYPE>
class SortedList;

template <class NODETYPE>
class SortedListIterator;


// --- LISTNODE CLASS ---
template <class NODETYPE>
class ListNode
{
    friend class SortedList<NODETYPE>;
    friend class SortedListIterator<NODETYPE>;


public:
    ListNode(const NODETYPE&);
    NODETYPE Info();

private:
    NODETYPE myInfo;
    ListNode* myNext;
};

// template class methods need this line because they are also template functions
template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE& value)
{
    myInfo = value;
    myNext = 0;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::Info()
{
    return myInfo;
}


// --- SORTEDLIST CLASS ---
template <class NODETYPE>
class SortedList
{

    friend class SortedListIterator<NODETYPE>;

public:
    SortedList();
    ~SortedList();
    SortedList(const SortedList<NODETYPE>&);
    void Insert(const NODETYPE&);
    bool IsEmpty();

    // overloaded assignment operator prototype
    SortedList<NODETYPE>& operator=(const SortedList<NODETYPE>&); // const because we won't modify the argument

private:
    ListNode<NODETYPE>* myFirst;
};

template <class NODETYPE>
SortedList<NODETYPE>::SortedList()
{
    // constructor
    myFirst = 0;
}

template <class NODETYPE>
SortedList<NODETYPE>::~SortedList()
{
    // destructor
    if (!IsEmpty())
    {
        cerr << "*** in destructor, destroying: ";
        ListNode<NODETYPE>* current = myFirst;
        ListNode<NODETYPE>* temp;
        while (current != 0)
        {
            cerr << " " << current->myInfo;
            temp = current;
            current = current->myNext;
            delete temp;
        }
        cerr << endl;
    }
}

template <class NODETYPE>
SortedList<NODETYPE>::SortedList(const SortedList<NODETYPE>& list)
{
    // copy constructor
    cerr << "*** in copy constructor" << endl;
    ListNode<NODETYPE>* listCurrent = list.myFirst;
    ListNode<NODETYPE>* newCurrent = 0;
    while (listCurrent != 0)
    {
        ListNode<NODETYPE>* temp = new ListNode<NODETYPE>(listCurrent->Info());
        if (newCurrent == 0)
        {
            myFirst = temp;
            newCurrent = myFirst;
        }
        else
        {
            newCurrent->myNext = temp;
            newCurrent = temp;
        }
        listCurrent = listCurrent->myNext;
    }
}

template <class NODETYPE>
void SortedList<NODETYPE>::Insert(const NODETYPE& value)  
{
    // Insert
    ListNode<NODETYPE>* toInsert = new ListNode<NODETYPE>(value);
    if (IsEmpty())
    {
        myFirst = toInsert;
    }
    else if (value < myFirst->Info())
    {
        toInsert->myNext = myFirst;
        myFirst = toInsert;
    }
    else
    {
        ListNode<NODETYPE>* temp = myFirst;
        toInsert->myNext = temp->myNext;
        temp->myNext = toInsert;
    }
}

template <class NODETYPE>
bool SortedList<NODETYPE>::IsEmpty()
{
    // IsEmpty
    return myFirst == 0;
}

// overloaded assignment operator definition
template <class NODETYPE>
SortedList<NODETYPE>& SortedList<NODETYPE>::operator=(const SortedList<NODETYPE>& list)
{
    /*
    Your function should first delete all the ListNode objects in the variable being assigned to (the left hand side of the =).
    It should then construct a copy of the list on the right hand side of the = to assign to the variable on the left hand side.
    How is this behavior different from the default assignment behavior?
    */

    // self-assignment guard
    if (this == &list) {
        cout << "*** Assigning a list to itself." << endl;
        return *this;
    }

    // first delete all the ListNode objects in the variable being assigned to
    // very similar to the existing destructor
    if (!IsEmpty())
    {
        cerr << "*** in operator=, destroying: ";
        ListNode<NODETYPE>* current = myFirst;
        ListNode<NODETYPE>* temp;
        while (current != 0)
        {
            cerr << " " << current->myInfo;
            temp = current;
            current = current->myNext;
            delete temp;
        }
        cerr << endl;
    }

    // construct a copy of the list on the right hand side of the = to asssign
    // very similar to the existing destructor
    ListNode<NODETYPE>* listCurrent = list.myFirst;

    ListNode<NODETYPE>* newCurrent = 0;
    while (listCurrent != 0)
    {
        ListNode<NODETYPE>* temp = new ListNode<NODETYPE>(listCurrent->Info());
        if (newCurrent == 0)
        {
            myFirst = temp;
            newCurrent = myFirst;
        }
        else
        {
            newCurrent->myNext = temp;
            newCurrent = temp;
        }
        listCurrent = listCurrent->myNext;
    }

    return *this; // return a SortedList<NODETYPE> object
}


// --- SORTEDLISTITERATOR CLASS ---
template <class NODETYPE>
class SortedListIterator {

// make the iterator class a friend of ListNode and SortedList so it can access their private data members to iterate

public:
    SortedListIterator(SortedList<NODETYPE>&); // one argument constructor, takes in a list
    bool MoreRemain();
    NODETYPE Next();

private:
    ListNode<NODETYPE>* currentNode;
};

// sorted list iterator constructor
template <class NODETYPE>
SortedListIterator<NODETYPE>::SortedListIterator(SortedList<NODETYPE>& list) {
    // set the current node of the iterator to the first node of the list
    currentNode = list.myFirst;
}

template <class NODETYPE>
bool SortedListIterator<NODETYPE>::MoreRemain() {
    // if the current node's next pointer is 0, there are no more elements
    // if (currentNode->myNext == 0) {
    if (currentNode == 0) {
       return false; 
    }
    return true;
}

template <class NODETYPE>
NODETYPE SortedListIterator<NODETYPE>::Next() {
    // return the value of the current node in the iterator and move to the next
    ListNode<NODETYPE>* returnNode = currentNode;
    currentNode = currentNode->myNext;

    return returnNode->myInfo;
}


#endif

/*
Questions:

1. Why is the overloaded assignment operator= necessary to achieve the correct behavior, why is it different from the deault behavior?

ans: I think the default assignment operator wouldn't delete the existing data in memory, it would just switch
     the pointer to a new address in memory, i.e. we'd have a memory leak on each assignment

2. Why does the SortedListIterator need to be a friend class of ListNode and SortedList

ans: Because SortedListIterator needs to access the private data members of ListNode (specifically myInfo in the Next() function)
     and SortedList (specifically myFirst in the constructor of SortedListIterator).

*/