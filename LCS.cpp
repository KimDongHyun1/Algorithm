#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char a[1001], b[1001];
int dp[1001][1001];
int i, j;

int main() {
	a[0] = 'a';
	b[0] = 'b';
	cin >> a + 1;
	cin >> b + 1;
	
	dp[0][0] = 0;
	for (int i = 1; i<strlen(a); i++) {
		for (int j = 1; j<strlen(b); j++) {
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[strlen(a) - 1][strlen(b) - 1] << '\n';
}

