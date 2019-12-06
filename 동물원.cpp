#include "pch.h"
#include <iostream>
using namespace std;
int dp[100001][3]; // 0은 이전줄이"00" , 1은 이전줄이"10", 2는 이전줄이"01"

int main()
{
	int n;
	cin >> n;
	
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 9901 << '\n';
	return 0;

	/*
	int n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}

	cout << dp[n] << '\n';
	return 0;
	*/
}
