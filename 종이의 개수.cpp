#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int a[3000][3000];
int cnt[4];// cnt[0]은 -1 , cnt[1]은 0, cnt[2]은 1의 갯수

bool same(int x, int y, int n) {
	int key = a[x][y];
	for (int i = x; i < n + x; i++) {
		for (int j = y; j < n + y; j++) {
			if (key != a[i][j])
				return false;
		}
	}
	return true;
}

void change(int x, int y, int n) {
	if (same(x, y, n)) {
		cnt[a[x][y] + 1] += 1;
	}
	else {
		int m = n / 3;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				change(x + i * m, y + j * m, m);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	change(0, 0, n);

	cout << cnt[0] << '\n';
	cout << cnt[1] << '\n';
	cout << cnt[2] << '\n';
}