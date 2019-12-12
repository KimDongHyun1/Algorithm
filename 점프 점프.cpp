#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int a[1001];
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) dp[i] = 1002;

	dp[1] = 1;
	for (int y = 2; y <= n; y++) {
		for (int x = 1; x < y; x++) {
			if (dp[x]!=1002 && (x + a[x] >= y)) {
				dp[y] = min(dp[y], dp[x] + 1);
			}


		}
	}

	if (dp[n] == 1002) cout << -1 << '\n';
	else cout << dp[n] - 1 << '\n';
	return 0;
}

