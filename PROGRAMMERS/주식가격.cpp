#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<pair<int, int>> S;

vector<int> solution(vector<int> prices) {
	vector<int> ans(prices.size(), 0);
	// prices(1,2,3,2,3) -> [4,3,1,1,0]
	for (int i = 0; i < prices.size(); i++) {
		if (S.empty()) S.push({ prices[i], i });
		else {
			while (!S.empty() && S.top().first > prices[i]) {
				ans[S.top().second] = i - S.top().second;
				S.pop();
			}
			S.push({ prices[i], i });
		}
	}


	while (!S.empty()) {
		ans[S.top().second] = prices.size() - 1 - S.top().second;
		S.pop();
	}

	return ans;
}



