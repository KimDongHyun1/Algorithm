#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
int cost[101][101];
bool check[101];
int n, k;
int cnt = -1;

void dfs(int node) {
	check[node] = true;
	cnt++;

	for (int i = 1; i <= n; i++) {
		if (!check[i] && cost[node][i]) {
			dfs(i);
		}
	}
}

int main() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		cost[x][y] = cost[y][x] = 1;
	}

	dfs(1);
	cout << cnt << '\n';
	return 0;
}