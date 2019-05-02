#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int now = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		now = now + a[i];
		ans = ans + now;
	}
	cout << ans << '\n';
}
