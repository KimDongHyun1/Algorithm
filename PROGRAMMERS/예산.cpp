#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
	sort(budgets.begin(), budgets.end());
	int left = 1;
	int right = budgets[budgets.size() - 1];
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i < budgets.size(); i++) {
			if (budgets[i] <= mid) sum += budgets[i];
			else sum += mid;
		}

		if (sum <= M) { // 통과
			ans = max(ans, mid);
			left = mid + 1;
		}
		else { // 통과 X
			right = mid - 1;
		}

	}

	return ans;
}