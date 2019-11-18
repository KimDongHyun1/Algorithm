#include "pch.h"
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int num[10];
int n, m;
int ans = INT_MAX;

int check(int i) {
	if (i==0) return !num[0];

	int cnt = 0;
	while (i) {
		if (num[i % 10]) return 0;
		i /= 10;
		cnt++;
	}

	return cnt;
}

void find() {
	for (int i = 0; i <= 2000000; i++) {
		
		int cnt = check(i);
		if (cnt) {
			int temp = cnt + abs(i - n);
			ans = min(ans, temp);
		}
	}
}

int main() {
	cin >> n;
	cin >> m;
	// 못쓰는거 1로 넣어두기.
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		num[x] = true; 
	}

	find();
	cout << min(ans, abs(n - 100)) << '\n';
}