#include <string>
#include <vector>
#include <queue>
using namespace std;

void Func(vector<int>& progresses, vector<int>& speeds, vector<int>& ans) {
	// progresses[93,30,55]  speeds[1,30,5]   return[2,1]

	queue<pair<int, int>> Q;
	for (int i = 0; i < progresses.size(); i++) {
		Q.push({ progresses[i], speeds[i] });
	}

	while (!Q.empty()) {
		while (!Q.empty() &&  Q.front().first < 100) {
			for (int i = 0; i < Q.size(); i++) {
				Q.push({ Q.front().first + Q.front().second, Q.front().second });
				Q.pop();
			}
		}

		int cnt = 0;
		while (!Q.empty() && Q.front().first >= 100) {
			Q.pop();
			cnt++;
		}

		ans.push_back(cnt);
	}
}


vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> ans;

	Func(progresses, speeds, ans);

	return ans;
}

