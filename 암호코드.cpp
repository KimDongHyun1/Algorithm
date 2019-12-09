#include <iostream>
#include <string>
#define MAX_LEN 1000000
using namespace std;
int dp[5001];

int main()
{
	string s;
	cin >> s; 
	s = "0" + s; // 0 2 5 1 1 4

	dp[0] = 1;
	for (int i = 1; i < s.size(); i++) {
		int pre = s[i - 1] - '0';
		int now = s[i] - '0';

		if ((i == 1 && now == 0) || (now < 0 || now>9)) { cout << 0 << '\n'; return 0; }
		

		if (now == 0) {
			dp[i] = dp[i - 2];
		}
		else if ((pre==1) || (pre==2 && now<=6)) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % MAX_LEN;
		}
		else {
			dp[i] = dp[i - 1];
		}
	}

	cout << dp[s.size() - 1] << '\n';
}

