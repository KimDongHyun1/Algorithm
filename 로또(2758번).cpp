#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[2001];
long long dp[2001][11];
int t, n, m;

int main()
{
	cin >> t;

	while (t--) {
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));

		cin >> n >> m;
		for (int i = 1; i <= m; i++) a[i] = i;

		for (int i = 1; i <= m; i++) {
			dp[i][1] = 1;

			for (int j = 2; j <= n; j++) {
				//dp[i][j] = dp[i / 2][j - 1];
				for (int k = 1; k <= i / 2; k++) {
					dp[i][j] += dp[k][j - 1];
				}


			}
		}

		long long ans = 0;
		for (int i = 1; i <= m; i++) {
			ans += dp[i][n];
		}

		cout << ans << '\n';
	}
	
	return 0;
}

