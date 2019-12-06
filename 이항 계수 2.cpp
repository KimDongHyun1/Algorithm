// 이항계수 공식이 dp[a][b] = dp[a-1][b-1] + dp[a-1][b] 라고 함
// 이유는 모르겠음 잘 생각해보기
// 비슷한 문제 : 다리 놓기

#include <iostream>
using namespace std;
int dp[1001][1001];
int n, k;

int solve(int n, int k) {
	if (k == 0 || n == k) return 1;
	if (k == 1) return n;
	if (dp[n][k]) return dp[n][k];

	dp[n][k] = (solve(n - 1, k - 1) + solve(n - 1, k)) % 10007;
	return dp[n][k];
}

int main()
{
	cin >> n >> k; // k <= n

	cout << solve(n, k) << '\n';
	return 0;
}