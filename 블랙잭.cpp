#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	int ans = m;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = a[i] + a[j] + a[k];
				if ((m - sum >= 0) && (m - sum < ans)) ans = m - sum;
			}
		}
	}

	cout << m - ans << '\n';
}