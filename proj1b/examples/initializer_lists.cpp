/*

The pro way of doing class member variable initilization is with
an initializer list, as demonstrated below, to clean up the 
constructors from all the member assignments

*/

#include <string>
#include <iostream>

using namespace std;

class Human {
private:
	int age;
	string name;
	double height;

public:

	// default constructor with an initializer list
	Human()
		: age(0), name("unknown"), height(5.5)
	{
		cout << "Default Human created..." << endl;
	}

	// non-default constructor with an initializaer list
	Human(int yearsOld, string firstLast, double tall)
		: age(yearsOld), name(firstLast), height(tall)
	{
		// more constructor code can go here...
		cout << "Custom Human created..." << endl;
	}

	int GetAge() const // const member function, promises not to modify what's passed in 
	{
		return age;
	}

};

int main() {

	// write some driver code
	Human trey;

	Human kelli(22, "Kelli Nagasawa", 5.17);

	cout << "Kelli's age is: " << kelli.GetAge() << endl;

	return 0;
}