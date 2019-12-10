#include "pch.h"
#include <cstring>
#include <iostream>
using namespace std;
long long a[2001];
long long dp[2001][2001];
int n, m, x, y;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int y = 1; y <= n; y++) {
		cin >> a[y];

		for (int x = 1; x <= y; x++) {
			if (x == y) { dp[x][y] = 1; continue; }

			// D가 1이면 그냥 두개만 비교 해주면 됨
			if (x + 1 == y) {
				if (a[x] == a[y]) dp[x][y] = 1;
				else dp[x][y] = 0;
			}
			// 자기랑 비교할꺼 빼고 나머지가 1이면 자기랑비교만 해주면 됨
			else {
				if (dp[x + 1][y - 1] == 1 && a[x] == a[y]) dp[x][y] = 1;
				else dp[x][y] = 0;
			}
			
		}

	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cout << dp[x][y] << '\n';
	}
}
