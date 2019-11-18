#include "pch.h"
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
bool visited[11];
int cost[11][11];
int n;
int ans = INT_MAX;

void dfs(int start, int x, int cnt, int sum) {
	if (start == x && cnt == n) {
		ans = min(ans, sum);
		return;
	}

	for (int y = 0; y < n; y++) {
		if (!visited[y] && cost[x][y]) {
			visited[y] = true;
			dfs(start, y, cnt + 1, sum + cost[x][y]);
			visited[y] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	for (int x = 0; x < n; x++) {
		dfs(x, x, 0, 0);
	}

	cout << ans << '\n';
	return 0;
}