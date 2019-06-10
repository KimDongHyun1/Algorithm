#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a;

	if (n < m + k - 1 || n > m*k) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 0; i < n; i++) {
			a.push_back(i + 1);
		}
		reverse(a.begin(), a.begin() + k);

		//현재갯수 : n-k, m-1개
		int ele = n - k;
		m = m - 1;
		int next = k;
		while (ele > 0 && m > 0) {
			if (ele%m == 0) {
				reverse(a.begin() + next, a.begin() + next + ele / m);
				next = next + ele / m;
				ele = ele - ele / m;
			}
			else {
				reverse(a.begin() + next, a.begin() + next + (ele / m + 1));
				next = next + ele / m + 1;
				ele = ele - (ele / m + 1);
			}
			m--;
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}