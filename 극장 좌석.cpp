// DP풀때 1~~~~ 생각 하는거 습관가지기

#include <iostream>
using namespace std;
int dp[41];
bool a[41];
int n, m, k;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		a[k] = true; // [ 1 (2) 3 (4) 5 6 (7) 8 9 ]
	}

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] || a[i-1]) { // 벽일 경우 || 이전이 벽일 경우
			dp[i] = dp[i - 1];
		}
		else {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
	}


	cout << dp[n] << '\n';
	return 0;
}

