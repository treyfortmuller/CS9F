#include "CLLNode.h"
#include <iostream>
using namespace std;

int main()
{
    const int N = 8;
    const int K = 2;

    // construct the circularly linked list of people
    // create the first link and then move "list" as the head of the list
    CLLNode* first = new CLLNode(N);
    CLLNode* list = first;
    for (int j = N-1; j > 0; j--)
    {
        CLLNode* newGuy = new CLLNode(j);
        list->insert(newGuy);
        list = newGuy;
    }
    list->print();

    // run the elimination game
    while (!list->lengthIsOne())
    // while there is more than one element in the linked list
    // each iteration through the while loop represents one "turn" of passing the marble K times
    {
        for (int j = 0; j < K; j++)
        {
            // step through the list K times
            list = list->next();
        }

        // TODO: Your code here
        CLLNode* temp = list;
        // pass the marble to next person in the circle
        list = list->next();

        // remove the person pointed to by "temp"
        temp->remove();
        list->print();
    }
    cout << "Only one person remains: ";
    list->print();

    return 0;
}
