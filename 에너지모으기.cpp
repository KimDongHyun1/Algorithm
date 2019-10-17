#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int rec(vector<int> &a, int index, int cur, int plus, int minus, int mul, int div) {
	if (index == a.size()) return cur;

	vector<int> res;

	if (plus > 0) res.push_back(rec(a, index + 1, cur + a[index], plus - 1, minus, mul, div));
	if (minus > 0) res.push_back(rec(a, index + 1, cur - a[index], plus, minus - 1, mul, div));
	if (mul > 0) res.push_back(rec(a, index + 1, cur * a[index], plus, minus, mul - 1, div));
	if (div > 0) res.push_back(rec(a, index + 1, cur / a[index], plus, minus, mul, div - 1));

	int ans = 0;
	for (int i = 0; i < res.size(); i++) {
		if (ans < res[i]) {
			ans = res[i];
		}
	}

	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;

	cout << rec(a, 1, a[0], plus, minus, mul, div) << '\n';
	return 0;
}