#include <string>
#include <iostream>

using namespace std;

struct Node {
	// a struct for a node in the linked list
	int data;
	Node* next; // a pointer to the next node in the list

	// a constructor for the node, uses an initializer list
	Node(int num_data, Node* link)
		: data(num_data),
		  next(link) { }
};

int main() {
	// create the first node in a linked list
	Node* zero = 0; // create a last node null pointer
	Node* first = new Node(1, zero); // create the first node passing a pointer to it
	// using new passes back a pointer to the object it creates

	// create another node which points to the first node
	first = new Node(2, first); // temp is a pointer to the first (leftmost) element of the linked list
	// for linked lists we'll have to keep track of the first (or last or both) object's pointer, here its first

	Node* temp;
	// iterate over the elements of the linked list and print them
	// this is a standard for loop for iterating over linked objects
	for (temp = first; temp != 0; temp = temp->next) { // use the selector operator to get the next pointer
		int info = temp->data;
		cout << info << endl;
	} // outputs 2, 1 as expected

	// alternatively
	temp = first;
	while (temp) { // equivilent to temp != 0
		int info = temp->data;
		cout << info << endl;
		temp = temp->next;
	}

	return 0;
}