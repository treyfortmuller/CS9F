#include "CLLNode.h"
#include <iostream>
using namespace std;

int main()
{
    const int N = 8;
    const int K = 2;

    CLLNode* list = 0;
    for (int j = N; j > 0; j--)
    {
        CLLNode* newGuy = new CLLNode(j);
        // TODO: Your code here
    }
    list->print();

    while (!list->lengthIsOne())
    {
        for (int j = 0; j < K; j++)
        {
            list = list->next();
        }

        // TODO: Your code here
    }
    cout << "Only one person remains: ";
    list->print();

    return 0;
}
