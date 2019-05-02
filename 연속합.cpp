#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
int a[100001];
int d[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[1] = a[1];
	for (int i = 2; i <= n; i++) {
		if (d[i - 1] < 0) d[i] = a[i];
		else d[i] = d[i - 1] + a[i];
	}

	int ans = d[1];
	for (int i = 2; i <= n; i++)
		ans = max(ans, d[i]);
	cout << ans << '\n';
}