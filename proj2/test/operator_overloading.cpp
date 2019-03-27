#include <iostream>

using namespace std;

class Vec2 {
public:
	Vec2() {
		// default constructor
		x = 0;
		y = 0;
	}

	Vec2(int x_num, int y_num) {
		// non-default constructor
		x = x_num;
		y = y_num;
	}

	void Print() {
		cout << "x: " << x << "\n";
		cout << "y: " << y << endl;
	}

	// example of an overloaded '+' operator
	void operator +(Vec2 other) {
		x += other.x;
		y += other.y;
	}

private:
	int x;
	int y;

};

int main() {
	Vec2 position1(2, 1);
	position1.Print();

	Vec2 position2(3, 4);
	position2.Print();

	position1 + position2;
	position1.Print();

	return 0;
}