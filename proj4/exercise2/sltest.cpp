#include <iostream>
using namespace std;

#include "sorted.lists.h"

int main()
{
    SortedList<int> list1, list2;
    SortedListIterator<int>* iter;
    list1.Insert(7);
    list1.Insert(10);
    list1.Insert(3);
    list1.Insert(5);
    cout << "List 1:";
    iter = new SortedListIterator<int>(list1);
    while (iter->MoreRemain())
    {
        cout << " " << iter->Next();
    }
    cout << endl;

    list2.Insert(8);
    list2.Insert(11);
    list2.Insert(4);
    list2.Insert(6);
    cout << "List 2:";
    iter = new SortedListIterator<int>(list2);
    while (iter->MoreRemain())
    {
        cout << " " << iter->Next();
    }
    cout << endl;

    cout << "Should get operator= call here"
         << " deleting elements of list 1." << endl;
    list1 = list2;
    cout << "List 1 after replacement:";
    iter = new SortedListIterator<int>(list1);
    while (iter->MoreRemain())
    {
        cout << " " << iter->Next();
    }
    cout << endl;

    cout << "Error msg should result here "
         << "from assigning list 2 to itself." << endl;
    list2 = list2;
    cout << "Should get copy constructor call here." << endl;
    SortedList<int> list3 = list2;
    cout << "Should get operator= call here "
         << "deleting old elements of list 1." << endl;
    list1 = list2;
    cout << "List 1 after assignment from list2:";
    iter = new SortedListIterator<int>(list1);
    while (iter->MoreRemain())
    {
        cout << " " << iter->Next();
    }
    cout << endl;

    cout << "List 2 after assignment:";
    iter = new SortedListIterator<int>(list2);
    while (iter->MoreRemain())
    {
        cout << " " << iter->Next();
    }
    cout << endl;

    cout << "Pairs of list 2 elements:";
    SortedListIterator<int> mIter(list2);
    int m, n;
    while (mIter.MoreRemain())
    {
        m = mIter.Next();
        SortedListIterator<int> nIter(list2);
        for (n = nIter.Next(); n != m; n = nIter.Next())
        {
            cout << " (" << m << " " << n << ") ";
        }
    }
    cout << endl;

    cout << "Should now get three destructor calls, "
         << "one each for list1, list2, and list3." << endl;
    return 0;
}
