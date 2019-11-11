#include "pch.h"
#include <iostream>
using namespace std;
int cost[501][501];
int dp[501][501];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;

int solve(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (x == 0 && y == 0) return 1;

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		if (cost[x + dx[i]][y + dy[i]] > cost[x][y])
			dp[x][y] += solve(x + dx[i], y + dy[i]);
	}

	return dp[x][y];
}

int main()
{
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cost[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(n - 1, m - 1) << '\n';
	
	return 0;
}
