#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[101][100001];
int w[101];
int v[101];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j]; // 지금까지 있는 것 중에 MAX 값
			if (j - w[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << dp[n][k] << '\n';
	return 0;
}