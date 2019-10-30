#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
char a[3000][3000];

void solve(int n, int x, int y) {
	if (n == 1) {
		a[x][y] = '*';
		return;
	}

	int temp = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			solve(temp, x+temp*i, y+temp*j);
		}
	}

	return;
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = ' ';
		}
	} // ' ' 이거 안하면 SPACE가 아닌 NULL이 저장되서


	solve(n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
	return 0;

}


