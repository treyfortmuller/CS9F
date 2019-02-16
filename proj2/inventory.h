#include <vector>
#include <string>
using namespace std;

class Inventory
{
public:
    Inventory();

    void Update(string item, int amount);

    void ListByName();

    void ListByQuantity();

private:
    // TODO: Your code here
};
