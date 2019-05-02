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
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b;
	vector<int> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int one = 0;
	int zero = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] > 1) b.push_back(a[i]);
		if (a[i] < 0) c.push_back(a[i]);
		if (a[i] == 1) one += 1;
		if (a[i] == 0) zero += 1;
	}

	sort(b.begin(), b.end(), cmp);
	sort(c.begin(), c.end());
	int ans = 0;

	for (int i = 0; i < b.size(); i++) {
		if (i % 2 == 1)
			ans += b[i - 1] * b[i];
		if (i == b.size() - 1 && i % 2 == 0)
			ans += b[i];
	}

	for (int i = 0; i < c.size(); i++) {
		if (i % 2 == 1)
			ans += c[i - 1] * c[i];
		if (i == c.size() - 1 && i % 2 == 0) {
			if (zero == 0) {
				ans += c[i];
			}
		}

	}

	cout << ans + one << '\n';

}