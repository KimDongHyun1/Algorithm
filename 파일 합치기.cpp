#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int INF = 2000000000;
int cost[501];
int dp[501][501];
int sum[501];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}

		for (int d = 1; d < k; d++) {
			for (int a = 1; a + d <= k; a++) {
				int b = a + d;
				dp[a][b] = INF;
				for (int mid = a; mid < b; mid++) {
					dp[a][b] = min(dp[a][b], dp[a][mid] + dp[mid + 1][b] + sum[b] - sum[a - 1]);
				}
			}
		}

		cout << dp[1][k] << '\n';
	}
	
	return 0;
}