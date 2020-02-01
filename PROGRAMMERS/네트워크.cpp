#include <vector>
#include <queue>
using namespace std;
bool visit[201];

void BFS(int i, vector<vector<int>> &computers, int n) {

	visit[i] = true;
	queue<int> Q;
	Q.push(i);

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		for (int y = 0; y < n; y++) {
			if (!visit[y] && computers[x][y]) {
				visit[y] = true;
				Q.push(y);
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			ans++;
			BFS(i, computers, n);
		}
	}

	return ans;
}

