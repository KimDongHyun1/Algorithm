#include "pch.h"
#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	int ans = 0;

	int n;
	cin >> n;
	int arr[101];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			ans += gcd(arr[i], arr[j]);
		}
	}

	cout << ans << '\n';
}