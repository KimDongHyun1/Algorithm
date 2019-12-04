#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[100001];
int a[101];
 
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//memset(dp, 100001, sizeof(dp)); memset은 0,-1 이 아닌수로 초기화 하면 안됨
	for (int i = 0; i < 100001; i++) dp[i] = 100001;

	for (int i = 0; i < n; i++) {
		dp[a[i]] = 1;
		for (int j = a[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
		}
	}

	if (dp[k] == 100001) cout << -1 << '\n';
	else cout << dp[k] << '\n';
	return 0;
}



