#include "pch.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int a[1001][1001];
int dp[1001][1001];
int n, m, ans;

int main()
{

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			a[i][j + 1] = s[j] - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]) {
				dp[i][j] = min({ dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1] }) + 1;
			}

			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans * ans << '\n';

	
}

