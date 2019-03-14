#ifndef INVENTORY_H // "if not defined"
#define INVENTORY_H // prevent the compiler from defining this file more than once

#include <vector>
#include <string>
using namespace std;

struct Item {
	// item struct to represent items in the inventory
	string name;
	int amount;

	// to have a vector of user-defined type
	// the type must have a default constructor
	Item() {
		// default constructor of the item struct
		name = "";
		amount = 0;
	}

	Item(string aname, int aamount) {
		// 2-parameter constructor for items
		name = aname;
		amount = aamount;
	}	
};

class Inventory
{
public:
    // Inventory();

    void Update(string item, int amount);

    void ListByName();

    void ListByQuantity();

    void PrintItem(const Item & entry);

    // bool CompareByName(Item & a, Item & b);

    // bool CompareByQuantity(Item & a, Item & b);

private:
    // TODO: Your code here
    vector<Item> itemList;

};

#endif