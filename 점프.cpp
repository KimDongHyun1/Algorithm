#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
long long dp[101][101];
long long a[101][101];
int n;

long long go(int x, int y) {
	if (x == n - 1 && y == n - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int k = 0; k < 2; k++) {
		int nx = x + dx[k] * a[x][y];
		int ny = y + dy[k] * a[x][y];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			dp[x][y] += go(nx, ny);
		}
	}

	return dp[x][y];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) << '\n';
	return 0;
	
}
