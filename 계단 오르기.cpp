#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
int d[100001][2];
int a[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[1][1] = a[1];
	d[2][1] = a[2];
	d[2][2] = a[1] + a[2];

	for (int i = 3; i <= n; i++) {
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	cout << max(d[n][1], d[n][2]) << '\n';
}