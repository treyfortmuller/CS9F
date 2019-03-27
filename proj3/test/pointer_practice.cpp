#include <iostream>

using namespace std;

#define LOG(x) cout << x << endl;

int main() {

	// declare a variable, which allocates some memory somewhere
	int var = 1;

	// find out the memory address of the int var by assigning its
	// adress to an untyped pointer with the & operator
	// the pointer is just a variable which holds memory addresses
	// memory address are just integers but we "type" pointers because presumably
	// the value stored at that memory address is of the same type
	int* ptr = &var;
	// example: 0x7ffd04e6a86c, the memory address of the var variable
	// given in hexidemical format

	cout << ptr << endl;

	// now we can gain access to the data stored at a particular memory address
	// by "dereferencing" the pointer using the * operator
	int var1 = *ptr; // now var1 == var == 1

	cout << var1 << endl;

	// we can also write to an address in memory using pointer dereferencing
	*ptr = 10; // update the data at the memory address to be 10

	cout << var << endl; // 10

	return 0;
}