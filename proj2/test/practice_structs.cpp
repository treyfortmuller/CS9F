#include <iostream>
#include <string>

using namespace std;

struct Book {
	string title;
	string author;
	int wordCount;
	int pageCount;

	// note we could also include constructors or member functions here as well
};

void addInfo(Book & book) {
	book.author = "Trey";
	book.wordCount = 50000;
	book.pageCount = 500;
}

int main() {

	// initialize a Book struct
	Book book1;
	book1.title = "Green Eggs and Ham"; // the data fields of a struct are public by default
	addInfo(book1);
	cout << book1.pageCount << endl;

	return 0;
}
