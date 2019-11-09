#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	priority_queue<int> big;
	priority_queue<int, vector<int>, greater<int>> small;

	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;

		if (big.size() > small.size()) small.push(cur);
		else big.push(cur);

		if (!small.empty() && big.top() < small.top()) {
			int smallTop = small.top();
			int bigTop = big.top();
			small.pop(); big.pop();
			big.push(smallTop);
			small.push(bigTop);
		}


		cout << big.top() << '\n';
	}
}