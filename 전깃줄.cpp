#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int first;
	int second;
} st;
int dp[102];
st val[102];

bool compare(st a, st b) {
	return a.first < b.first;
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val[i].first >> val[i].second;
	}

	sort(val, val + n, compare);
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j <= i; j++) {
			if (val[i].second > val[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < dp[i]) ans = dp[i];
	}

	cout << n - ans << '\n';
}