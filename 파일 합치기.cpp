#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int INF = 2000000000;
int cost[501];
int dp[501][501];

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		int row, col;
		cin >> row >> col;
		v.push_back(make_pair(row, col));
	}

	for (int d = 1; d < n; d++) {
		for (int a = 0; a + d <= n; a++) {
			int b = a + d;
			dp[a][b] = INF;
			
			for (int mid = a; mid < b; mid++) {
				dp[a][b] =
					min(dp[a][b], dp[a][mid] + dp[mid + 1][b] + cost[a].first*cost[a].second*cost[b].second);
			}
		}
	}

	cout << dp[0][n - 1] << '\n';

	
}