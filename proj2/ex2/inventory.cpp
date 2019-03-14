#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for the sorting algo
#include "inventory.h"

using namespace std;

// Inventory::Inventory()
// {

// }

void Inventory::Update(string item, int amount)
{
	// a simple sequential search to see if the update item is already in stock
	int index = -1;

	for (int i = 0; i < itemList.size(); i++) {
		if (itemList[i].name == item) {
			index = i;
		}
	}

	if (index != -1) {
		// the item already exists at some index
		itemList[index].amount += amount; 
	} else {
		// the item is not already in the list
		Item newItem(item, amount);
		itemList.push_back(newItem);
	}
}

void Inventory::ListByName()
{
	// sort the vector by name
	// sort(itemList.begin(), itemList.end(), CompareByName);

	// C++11 lambda for sorting
	// compare returns <0 if a.name is before b.name in alpha order
	// returns 0 if they are the same
	// returns >0 if a.name is after b.name in alpha order 
	sort( itemList.begin(), itemList.end(), []( const Item &left, const Item &right ){ 
		
		bool leftBeforeRight = true;
		int alpha = left.name.compare(right.name);

		if (alpha > 0) {
			leftBeforeRight = false;
		}

		return leftBeforeRight; } );

	cout << "\nBY NAME:" << endl;
	for (int i = 0; i < itemList.size(); i++) {
		PrintItem(itemList[i]);
	}
}

void Inventory::ListByQuantity()
{
	// sort the vector by quantity, this has issues...
	// sort(itemList.begin(), itemList.end(), CompareByQuantity);

	// C++11 lambda for sorting
	sort( itemList.begin(), itemList.end(), []( const Item &left, const Item &right ){ 
		return ( left.amount < right.amount ); } );

	cout << "\nBY QUANTITY:" << endl;
	for (int i = 0; i < itemList.size(); i++) {
		PrintItem(itemList[i]);
	}
}

void Inventory::PrintItem(const Item & entry) {
	string entryName = entry.name;
	int entryAmount = entry.amount;

	cout << "----------------\n";
	cout << "item: " + entryName + "\n";
	cout << "amount: ";
	cout << entryAmount;
	cout << endl;
}

// bool Inventory::CompareByName(Item & a, Item & b)
// {
// 	// compare returns <0 if a.name is before b.name in alpha order
// 	// returns 0 if they are the same
// 	// returns >0 if a.name is after b.name in alpha order 
//     bool aBeforeB = true;
//     int alpha = a.name.compare(b.name);

//     if (alpha > 0) {
//     	aBeforeB = false;
//     }

//     return aBeforeB;
// }

// bool Inventory::CompareByQuantity(Item & a, Item & b)
// {
//     return a.amount < b.amount;
// }


// int main() {
// 	// temporary main function for debugging the inventory class
// 	cout << "inventory class debug..." << endl;

// 	Inventory Items;
// 	Items.Update("apple", 2);
// 	Items.Update("bapple", 1);

// 	Items.ListByName();
// 	Items.ListByQuantity();

// 	return 0;
// }