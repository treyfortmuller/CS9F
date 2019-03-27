#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for the sort function

using namespace std;

struct Person {
	string name;
	int age;

	void Print() {
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
	}
};

bool compareByAge(Person & person1, Person & person2) {
	// write a "compareBy..." function that returns true if
	// the first arg appears before the second arg in a sorted list
	if (person1.age < person2.age) {
		return true;
	}

	return false;
}

bool compareByName(Person & person1, Person & person2) {
	string name1 = person1.name;
	string name2 = person2.name;
	if (name1.compare(name2) <= 0) {
		return true;
	}

	return false;
}

int main() {

	Person Trey;
	
	Trey.name = "Trey";
	Trey.age = 25;

	Person Kelli;

	Kelli.name = "Kelli";
	Kelli.age = 23;

	// declare a vector of type 'Person' to sort
	vector<Person> list;
	list.push_back(Trey);
	list.push_back(Kelli);

	// sort the list by Age
	sort(list.begin(), list.end(), compareByAge);

	for (int i=0; i < list.size(); i++) {
		list[i].Print();
	}

	// sort the list by Name
	sort(list.begin(), list.end(), compareByName);

	for (int i=0; i < list.size(); i++) {
		list[i].Print();
	}

	return 0;
}