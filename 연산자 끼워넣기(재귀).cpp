#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

pair<int,int> rec(vector<int> &a, int index, int cur, int plus, int minus, int mul, int div) {
	if (index == a.size()) return make_pair(cur, cur);

	vector<pair<int,int>> res;

	if (plus > 0) res.push_back(rec(a, index + 1, cur + a[index], plus - 1, minus, mul, div));
	if (minus > 0) res.push_back(rec(a, index + 1, cur - a[index], plus, minus - 1, mul, div));
	if (mul > 0) res.push_back(rec(a, index + 1, cur * a[index], plus, minus, mul - 1, div));
	if (div > 0) res.push_back(rec(a, index + 1, cur / a[index], plus, minus, mul, div - 1));

	auto ans = res[0];
	for (auto x : res) {
		if (ans.first < x.first) ans.first = x.first;
		if (ans.second > x.second) ans.second = x.second;
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


	pair<int, int> answer;
	answer = rec(a, 1, a[0], plus, minus, mul, div);
	cout << answer.first << '\n';
	cout << answer.second << '\n';
	return 0;
}