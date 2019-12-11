#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int dp[101][10001];
int m[101];
int c[101];
int N, M, x, y;
int ans = 10000;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> m[i];
	for (int i = 1; i <= N; i++) cin >> c[i];

	dp[1][c[1]] = m[1];
	for (int x = 2; x <= N; x++) {
		for (int y = 0; y <= 10000; y++) {
				
			if (y - c[x] >= 0) dp[x][y] = max(dp[x][y], dp[x - 1][y - c[x]] + m[x]);
			dp[x][y] = max(dp[x][y], dp[x - 1][y]);
			
			if (dp[x][y] >= M) ans = min(ans, y);
		}
	}

	cout << ans << '\n';
	return 0;
}
