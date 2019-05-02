#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
int a[1001];
int d[1001];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] < a[j]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i]);
	}

	cout << ans << '\n';
	return 0;
}