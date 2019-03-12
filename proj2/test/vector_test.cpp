#include <iostream>
#include <sstream>
#include <string>
#include <vector> // the C++ std vector class

using namespace std;

struct Contact { // a struct for a contact entry
	string name;
	int number;
	string email;	

	// to use this struct in a vector, we need a default constructor
	Contact() {
		name = "no name";
		number = 0;
		email = "email@gmail.com";
	}

	// a 3-parameter constructor
	Contact(string aname, int anumber, string aemail) {
		name = aname;
		number = anumber;
		email = aemail;
	}

	void printContact() const {
		stringstream stream; // you have to use string streams in C++ for concatinating ints
		
		cout << "-----------------------" << endl;
		cout << "name: " + name << endl;
		
		stream << "number: " << number << endl;
		cout << stream.str();
		
		cout << "email: " + email << endl;
	}

};

int main() {

	// intialize an int vector with length 5
	vector<int> intList(5);
	intList[0] = 2; // assignment of the zeroth index
	cout << intList[0] << endl;

	// now a vector of user-defined type using the Contact struct
	vector<Contact> contactList(5);
	contactList[0].name = "Trey Fortmuller";
	contactList[0].number = 1231231234;
	contactList[0].email = "tfort@gmail.com";

	// print the name of the contact at 0
	cout << contactList[0].name << endl;

	// using my custom print contact function for all the info
	contactList[0].printContact();
	contactList[1].printContact(); // prints the default constructed struct

	// use the 3-parameter constructor
	contactList[2] = Contact("Kelli Nags", 1231231234, "kelli@gmail.com");
	contactList[2].printContact();

	// the size vs capacity of the contact list vector
	// and how they change using push_back(), resize(), and reserve()
	
	// size and capacity are the same when the vector is initialized,
	// default objects fill the capacity of the vector
	cout << contactList.size() << endl; // == 5
	cout << contactList.capacity() << endl; // == 5

	// push_back() is used to add elements to the end of a vector, the vector
	// resizes to accomadate by DOUBLING its capacity
	// push_back is like python's append()
	contactList.push_back(Contact("John Appleseed", 1231231234 ,"john123@gmail.com"));
	cout << contactList.size() << endl; // == 6
	cout << contactList.capacity() << endl; // == 10

	// print out the last element of the vector, John Appleseed's card
	contactList[contactList.size()-1].printContact();

	// create a list with size 0 to be used with push_back but reserve
	// more space to avoid copying
	vector<int> numList; // size == 0, capacity == 0
	numList.reserve(2048); // size == 0, capacity == 2048

	numList.push_back(5);
	cout << numList.size() << endl; // == 1
	cout << numList.capacity() << endl; // == 2048

	// deleting the last element using pop_back()
	numList.pop_back();
	cout << numList.size() << endl; // == 0
	cout << numList.capacity() << endl; // == 2048

	return 0;
}