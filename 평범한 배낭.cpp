#include "pch.h"
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
			if (j - w[i] >= 0) { // 만약에 현재 N값의 무게가 KEY 값보다 작다면
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]); // 지금까지의 MAX값 vs W를 뺸 전꺼의 MAX 값 + 현재 N의 VAL의값 
			}
		}
	}

	cout << dp[n][k] << '\n';
	return 0;
}