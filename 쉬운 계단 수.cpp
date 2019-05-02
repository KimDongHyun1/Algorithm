#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
long long d[101][10];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			d[i][j] = 0;
			if (j > 0) d[i][j] += d[i - 1][j - 1];
			if (j < 9) d[i][j] += d[i - 1][j + 1];
			d[i][j] %= 1000000000;
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += d[n][i];
	}
	cout << (ans) % 1000000000 << '\n';
}