// 이거 막 X*X 이거 조합으로 바로 구할 수 있는거 있었는데 찾아보기

#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int dp[15][15];
int n, m, k, a, b, ans1, ans2;

int dfs(int x, int y) {
	if (x == a && y == b) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int k = 0; k < 2; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m && nx <= a && ny <= b) {
			dp[x][y] += dfs(nx, ny);
		}

	}

	return dp[x][y];
}

int dfs2(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int k = 0; k < 2; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			dp[x][y] += dfs2(nx, ny);
		}
	}

	return dp[x][y];
}

int main()
{
	cin >> n >> m >> k;
	
	// k의 좌표 구하기
	// 이거 말고도 2중 for문 돌려서 Count++로 해줄 수 있음
	a = (k - 1) / m;
	b = (k - 1) % m;

	if (k == 0) {
		memset(dp, -1, sizeof(dp));
		cout << dfs2(0, 0) << '\n';
	}
	else {
		memset(dp, -1, sizeof(dp));
		ans1 = dfs(0, 0);

		memset(dp, -1, sizeof(dp));
		ans2 = dfs2(a, b);

		cout << ans1 * ans2 << '\n';
	}
	
	return 0;
}
