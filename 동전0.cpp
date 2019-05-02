#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n, k;
	int arr[11];
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}

	int cnt = 0;

	for (int i = n; i >= 1; i--) {
		if (k >= arr[i]) {
			cnt += k / arr[i];
			k %= arr[i];
		}
	}

	cout << cnt << '\n';
}