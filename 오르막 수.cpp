#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
int d[1001][10];

int main()
{
	for (int i = 0; i <= 9; i++) d[1][i] = 1;
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= 10007;
			}
		}
	}
	long long cnt = 0;
	for (int i = 0; i <= 9; i++)
		cnt += d[n][i];
	cout << (cnt) % 10007 << '\n';

}