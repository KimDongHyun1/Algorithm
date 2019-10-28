#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
bool a[15][15];
int n;
bool cols[15];
bool rights[40];
bool lefts[40];



int check(int row) {
	if (row == n) return 1;

	int cnt = 0;
	for (int col = 0; col < n; col++) {
		if (!cols[col] && !rights[row + col] && !lefts[row - col + n]) {
			cols[col] = true;
			rights[row + col] = true;
			lefts[row - col + n] = true;
			a[row][col] = true;

			cnt = cnt + check(row + 1);

			cols[col] = false;
			rights[row + col] = false;
			lefts[row - col + n] = false;
			a[row][col] = false;
		}
	}

	return cnt;
}

int main() {
	cin >> n;

	int ans = check(0);
	cout << ans << '\n';
	return 0;
}
