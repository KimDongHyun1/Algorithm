#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[101];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a, a + n + 1);

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - a[i]];
		}
	}

	cout << dp[k] << '\n';
	return 0;
}