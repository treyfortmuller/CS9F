#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <cassert>

template <class NODETYPE>
class SortedList;
template <class NODETYPE>
class SortedListIterator;
template <class NODETYPE>

class ListNode
{
    friend class SortedList<NODETYPE>;

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

template <class NODETYPE>
class SortedList
{
public:
    SortedList();
    ~SortedList();
    SortedList(const SortedList<NODETYPE>&);
    void Insert(const NODETYPE&);
    bool IsEmpty();

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
void SortedList<NODETYPE>::Insert(const NODETYPE&)
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
        for (temp = myFirst; temp->myNext != 0 && temp->myNext->Info() < value; temp = temp->next)
        {
        }
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
#endif
