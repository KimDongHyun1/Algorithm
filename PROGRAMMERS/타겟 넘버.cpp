#include <vector>
using namespace std;
int ans;

void DFS(vector<int> numbers, int target, int sum, int idx) {
	if (idx == numbers.size()) {
		if (sum == target) ans++;
		return;
	}

	DFS(numbers, target, sum + numbers[idx], idx + 1);
	DFS(numbers, target, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
	DFS(numbers, target, 0, 0);
	return ans;
}