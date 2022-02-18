#include <iostream>
#include <vector>
using namespace std;

void printVector (vector<int> const &numbers) {
	cout << "{" << endl << "\t";
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, ",\n\t"));
	printf("\n\033[F}");
}

vector<int> howSum (int target, vector<int> numbers) {
	if (target == 0) {
		return vector<int>();
	}

	if (target < 0)
		return vector<int>(-1);
	for (int number : numbers) {
		int remainder = target - number;
		vector<int> result = howSum(remainder, numbers);
		if (result.at(0) != -1) {
			result.push_back(number);
			return result;
		}
	}
	return vector<int>(-1);
}

int main (int argc, char** argv) {
	howSum(7, vector<int>{2, 3, 4, 7});
	//printVector(howSum(7, vector<int>{2, 3, 4, 7}));
	//printVector(howSum(7, vector<int>{2, 3, 2, 7}));
	return 0;
}
