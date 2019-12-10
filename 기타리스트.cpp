#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
bool dp[101][1001];
int a[101];
int N, S, M;

int main()
{
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) cin >> a[i];

	dp[0][S] = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j] && j + a[i] <= M) {
				dp[i][j + a[i]] = true;
			}
			if (dp[i - 1][j] && j - a[i] >= 0) {
				dp[i][j - a[i]] = true;
			}
		}

	}
	
	int ans = -1;
	for (int i = 1000; i >= 0; i--) {
		if (dp[N][i]) {
			ans = i;
			break;
		}
	}

	cout << ans << "\n";
	return 0;
}
