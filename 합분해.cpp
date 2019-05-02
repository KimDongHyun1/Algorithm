#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
int d[201][201];

int main()
{
	int n, k;
	cin >> n >> k;

	d[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int p = 0; p <= j; p++) {
				d[i][j] += d[i - 1][j - p];
				(d[i][j]) %= 1000000000;
			}
		}
	}

	cout << (d[k][n]) % 1000000000 << '\n';
}