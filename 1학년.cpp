// 기타리스트랑 거의 똑같음

#include <iostream>
using namespace std;
long long dp[101][21];
int a[101];
int N;

int main()
{
	cin >> N; // 11
	for (int i = 1; i <= N; i++) cin >> a[i];
	// 8 3 2 4 8 7 2 4 0 8 8 

	dp[1][a[1]] = true;
	for (int i = 2; i <= N-1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] && j + a[i] <= 20) {
				dp[i][j + a[i]] += dp[i - 1][j];
			}
			if (dp[i - 1][j] && j - a[i] >= 0) {
				dp[i][j - a[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[N - 1][a[N]] << '\n';
	return 0;
}

