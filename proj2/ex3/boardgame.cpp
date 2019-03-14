#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Board {
public:
	Board() {
		// default constructor to initialize all cell to periods
		int rows = 19;
		int cols = 19;

		grid.resize(rows);
		for (int i = 0; i < rows; i++) {
			grid[i] = vector<char>(19);
			for (int j = 0; j < cols; j++) {
				grid[i][j] = '.';
			}
		}
	}

	void SetCell(int player, int row, int col, char c) {
		// stores the given character argument at board position [row][col], 
		// computed from the given player's perspective
		if (player == 0) {
			grid[row][col] = c;
		} else {
			// compute the coordinates in the opposite reference frame
			int newRow = (grid.size() - 1) - row;
			int newCol = (grid[row].size() - 1) -col;
			grid[newRow][newCol] = c;
		}
	}

	void Print(int player) {
		// prints the board from the given player's perspective, numbered 0 and 1
		if (player == 0) {
			// forward iterate through the grid
			cout << "Player 1 sees:\n";
			for (int i = 0; i < grid.size(); i++) {
				for (int j = 0; j < grid[i].size(); j++) {
					cout << grid[i][j] << " ";
				}
				cout << endl;
			}
		} else {
			// backwards iterate through the grid
			cout << "Player 2 sees:\n";
			for (int i = grid.size() - 1; i >= 0; i--) {
				for (int j = grid[i].size() - 1; j >= 0; j--) {
					cout << grid[i][j] << " ";
				}
				cout << endl;
			}
		}
	}

private:
	// a vector of vectors of chars to represent the grid of the board
	vector<vector<char> > grid;

};

int main() {
	// Your test cases should include calls to SetCell and Print for each of the two players.
	Board board;

	board.Print(0);
	board.Print(1);

	board.SetCell(0, 1, 1, 'X');

	board.Print(0);
	board.Print(1);

	board.SetCell(1, 1, 1, 'X');

	board.Print(0);
	board.Print(1);


	return 0;
}