// 증가하는 수열인가 그거랑 아예 똑같음


#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int a[1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';
}
