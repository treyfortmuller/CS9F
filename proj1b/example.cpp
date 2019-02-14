// pass by reference example

#include <iostream>

using namespace std;

void change(int& num) {

	num += 1;

}

int main() {

	int num = 0;

	change(num);

	cout << num << endl;

	return 0;
}