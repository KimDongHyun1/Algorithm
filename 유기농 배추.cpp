#include "pch.h"
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int cost[51][51];
bool check[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int m, n, k, t;
int ans = 0;

void dfs(int x, int y) {
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) {
			if (!check[x1][y1] && cost[x1][y1]) {
				check[x][y] = true;
				dfs(x1, y1);
			}

		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		memset(cost, 0, sizeof(cost));
		memset(check, 0, sizeof(check));
		ans = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++) {
			int y, x;
			cin >> y >> x;
			cost[x][y] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!check[i][j] & cost[i][j]) {
					dfs(i,j);
					ans++;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}