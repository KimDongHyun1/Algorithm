#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a, b;
int Max = 0;
int dp[1001][1001];
string s[1001][1001];

int main() {
	cin >> a; a = "0" + a;
	cin >> b; b = "0" + b;

	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				s[i][j] = s[i - 1][j - 1] + b[j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				
				if (s[i - 1][j].size() > s[i][j - 1].size()) {
					s[i][j] = s[i - 1][j];
				}
				else {
					s[i][j] = s[i][j - 1];
				}
			}

		}
	}

	cout << dp[a.size() - 1][b.size() - 1] << '\n';
	cout << s[a.size() - 1][b.size() - 1] << '\n';
	return 0;
}