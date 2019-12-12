#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;
long long dp[65][10];
int t, n;
int main()
{
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 0; i <= 9; i++) dp[1][i] = 1;

		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= j; k++) {
					dp[i][j] += dp[i - 1][k];
				}
			}
		}

		long long ans = 0;
		for (int i = 0; i <= 9; i++) ans += dp[n][i];
		cout << ans << '\n';
	}

	return 0;
}


