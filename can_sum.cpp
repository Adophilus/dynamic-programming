#include <vector>
#include <map>
using namespace std;

bool canSum (int target, vector<int> numbers, map<int, bool> memo = map<int, bool>()) {
	if (target == 0)
		return true;
	if (target < 0)
		return false;
	if (memo[target])
		return memo[target];

	for (int number : numbers) {
		memo[target - number] = canSum(target - number, numbers);
		if (memo[target - number])
			return true;
	}
	return false;
}

int main (int argc, char** argv) {
	printf("%d\n", canSum(7, vector<int>(2, 4)));
	printf("%d\n", canSum(7, vector<int>{2, 4, 3, 7}));
	printf("%d\n", canSum(300, vector<int>{7, 14}));
	return 0;
}
