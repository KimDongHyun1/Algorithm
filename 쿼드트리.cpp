#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int a[64][64];

bool same(int x, int y, int n) {
	int k = a[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (k != a[i][j])
				return false;
		}
	}
	return true;
}

void change(int x, int y, int n) {
	if (same(x, y, n)) {
		cout << a[x][y];
		return;
	}

	int m = n / 2;
	cout << "(";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			change(x + i * m, y + j * m, m);
		}
	}
	cout << ")";
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	change(0, 0, n);
}