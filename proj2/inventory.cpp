#include <iostream>
#include <string>
#include <vector>
#include "inventory.h"

using namespace std;

Inventory::Inventory()
{

}

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
	// TODO: sort the list by name
	cout << "BY NAME:" << endl;
	for (int i = 0; i < itemList.size(); i++) {
		PrintItem(itemList[i]);
	}
}

void Inventory::ListByQuantity()
{
	// TODO: sort the list by quantity
	cout << "BY QUANTITY:" << endl;
	for (int i = 0; i < itemList.size(); i++) {
		PrintItem(itemList[i]);
	}
}

void Inventory::PrintItem(Item & entry) {
	string entryName = entry.name;
	int entryAmount = entry.amount;

	cout << "----------------\n";
	cout << "item: " + entryName + "\n";
	cout << "amount: ";
	cout << entryAmount;
	cout << endl;

}

int main() {
	// temporary main function for debugging the invectory class
	cout << "inventory class debug..." << endl;

	Inventory Items;
	Items.Update("apple", 2);
	Items.Update("apple", 3);

	Items.ListByName();
	Items.ListByQuantity();

	return 0;
}