#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int dp[501][501];
int n, r, c;

typedef struct {
	int r;
	int c;
} st;

st cost[501];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		cost[i].r = x;
		cost[i].c = y;
	}

	for (int d = 1; d < n; d++) {
		for (int a = 1; a <= n - d; a++) {
			int b = a + d;
			dp[a][b] = INT_MAX;
			
			for (int mid = a; mid < b; mid++) {
				dp[a][b] = min(dp[a][b], dp[a][mid] + dp[mid + 1][b] + cost[a].r * cost[mid].c * cost[b].c);
			}
		}
	}

	cout << dp[1][n] << '\n';
}
