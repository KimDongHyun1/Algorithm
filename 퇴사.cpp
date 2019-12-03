#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int t[1001];
int p[1001];

int main()
{
	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	// 만약 1이라면 dp[i-1] + a[i] , j탐색-> a[j] + dp[j]
	// 아니라면 dp[i-1] , j탐색- a[j] + dp[j]
	for (int i = 1; i <= n; i++) {
		if (t[i] == 1) {
			dp[i] = dp[i - 1] + p[i];
		}
		else {
			dp[i] = dp[i - 1];
		}

		for (int j = 1; j < i; j++) {
			if (t[j] + j - 1 == i) {
				dp[i] = max(dp[i], dp[j-1] + p[j]);
			}
		}

	}
	
	cout << dp[n] << '\n';
	return 0;
}

