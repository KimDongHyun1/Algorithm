#include <vector>
#include <queue>
using namespace std;
priority_queue<int> PQ;
queue<pair<int, int>> Q;

int solution(vector<int> priorities, int location) {
	int ans = 1;

	for (int i = 0; i < priorities.size(); i++) {
		Q.push({ priorities[i], i });
		PQ.push(priorities[i]);
	}

	bool flag = false;
	while (true) {
		while (Q.front().first != PQ.top()) {
			Q.push({ Q.front().first, Q.front().second });
			Q.pop();
		}

		while (Q.front().first == PQ.top()) {
			if (Q.front().second == location) {
				flag = true;
				break;
			}
			else {
				PQ.pop();
				Q.pop();
				ans++;
			}
		}

		if (flag) break;
	}


	return ans;
}
