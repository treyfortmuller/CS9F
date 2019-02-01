#include <iostream>
#include <vector>

bool exit = false; // to terminate the program once finished
int current; // the current integer entered by user
int previous = -1; // the previous integer entered by user
std::vector<int> subList; // the subtotal list
std::vector<int> totalList; // the grand total list

int ComputeSum(std::vector<int> toSum){
	// a function to compute the sum of all elements of a std::vector
	int sum = 0;

	for(int i = 0; i < toSum.size(); i++){
		sum += toSum[i];
	}

	return sum;
}

int main(){
	std::cout << "Enter integers:\n";

	while(!exit){
		std::cin >> current; // grab the integer from input

		if(current == 0){
			// compute a subtotal and clear the subtotal
			std::cout << "Subtotal " << ComputeSum(subList) << "\n";
			subList.clear();
		} if (current == 0 && previous == 0) {
			// compute the grand total and terminate the while loop
			std::cout << "Total " << ComputeSum(totalList) << "\n";
			exit = true; 
		} else {
			// append the new entry to the vectors
			subList.push_back(current);
			totalList.push_back(current);
		}
		previous = current;
	}
	return 0;
}
