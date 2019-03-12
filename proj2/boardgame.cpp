#include <iostream>
#include <string>

using namespace std;

class Board {
public:
	Board() {
		// default constructor to initialize all cell to periods
	}

	void SetCell(int player, int row, int col, char c) {
		// stores the given character argument at board position [row][col], 
		// computed from the given player's perspective. For example, on the 3-by-3 board that, 
		// viewed from player 0's perspective, contains

	}

	void Print(int player) {
		// prints the board from the given player's perspective, numbered 0 and 1
	}




private:
	// intiialize a char vector with 19 periods
	vector<char> rows(19, ".");

	// intialize a vector of 19 char vectors...
	vector<vector<char> chars> columns(19);


};

int main() {
	// Your test cases should include calls to SetCell and Print for each of the two players.

	return 0;
}