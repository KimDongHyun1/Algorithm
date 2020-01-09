#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int visit[10001];
int n, m, ans, temp;
priority_queue<int, vector<int>, greater<int>> PQ;
vector<int> v[10001];

int dfs(int x) {
	visit[x] = true;

	int cnt = 1;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (!visit[y]) {
			cnt += dfs(y);
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[y].push_back(x);
	}

	for (int x = 1; x <= n; x++) {
		memset(visit, 0, sizeof(visit));
		temp = dfs(x);
		if (ans < temp) {
			while (!PQ.empty()) PQ.pop();

			PQ.push(x);
			ans = temp;
		}
		else if (ans == temp) {
			PQ.push(x);
		}
	}

	while (!PQ.empty()) {
		cout << PQ.top() << ' ';
		PQ.pop();
	}

	return 0;
}
