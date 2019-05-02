#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
int a[10001];
int d[10001][3];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[1][0] = 0; d[1][1] = a[1]; d[1][2] = a[1];
	for (int i = 2; i <= n; i++) {
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}
	cout << max(d[n][0], max(d[n][1], d[n][2])) << '\n';
}