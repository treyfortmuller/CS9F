#include "lists.h"
#include <iostream>
using namespace std;

ListNode* fromInput(istream& is)
// a function which returns a pointer to a ListNode object
// takes in an input stream reference as an argument
// this sets up our linked list from a test file
{
    int k;
    ListNode* head = 0;

    while (is >> k)
    {
        head = new ListNode(k, head);
    }

    return head;
}

int main()
{
    ListNode* list = fromInput(cin);
    list->print();

    if (list)
    {
        delete list;
        // implicitly calls the destructor on the first element of the linked list
    }
    list = 0;

    return 0;
}
