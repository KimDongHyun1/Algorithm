#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(int u, int v) {
	return u > v;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	while (k--) {
		if (n > m * 2) {
			n--;
		}
		else {
			m--;
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (n - 2 >= 0) {
			n -= 2;
			ans++;
		}
		else {
			break;
		}
	}
	cout << ans << '\n';
}