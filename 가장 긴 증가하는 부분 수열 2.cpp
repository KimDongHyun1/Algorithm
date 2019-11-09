#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> v;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;

		if (i == 0 || cur > v.back()) {
			v.push_back(cur);
			cnt++;
		}
		else {
			auto iter = lower_bound(v.begin(), v.end(), cur);
			*iter = cur;
		}
	}

	cout << cnt << '\n';
	return 0;
}
