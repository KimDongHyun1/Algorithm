#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int> perm(n);
	for (int i = 0; i < n / 2; i++) {
		perm[i] = 1;
	}

	sort(perm.begin(), perm.end());
	int ans = 2147483647;

	do {
		vector<int> first, second;
		for (int i = 0; i < n; i++) {
			if (perm[i] == 0) {
				first.push_back(i);
			}
			else {
				second.push_back(i);
			}
		}

		int one = 0;
		int two = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;
				one += arr[first[i]][first[j]];
				two += arr[second[i]][second[j]];
			}
		}

		int diff = one - two;
		if (diff < 0) diff = -diff;
		if (ans > diff) ans = diff;
	} while (next_permutation(perm.begin(), perm.end()));

	cout << ans << '\n';
	return 0;
}