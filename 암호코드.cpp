#include "pch.h"
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int dp[501];

int main() {
	string s;
	cin >> s;
	s = " " + s;

	dp[0] = 1;
	for (int i = 1; i < s.size(); i++) {
		int x = s[i] - '0';

		if (1<=x && x<=9) {
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;
		}

		if (i == 1) continue;
		if (s[i - 1] == '0') continue;

		x = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (10 <= x && x <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		}

	}

	cout << dp[s.size()-1] << '\n';
}