#include <iostream>
#include <vector>
using namespace std;
int n, r, c;
int cnt = 0;

int jegob(int count) {
	int num = 1;
	while (count) {
		num *= 2;
		count--;
	}
	return num;
}

void check(int x, int y, int n) {
	if (x == r && y == c) {
		cout << cnt << '\n';
		return;
	}
	if (n == 1) {
		cnt++;
		return;
	}
	if (!(x <= r && r < x + n && y <= c && c < y + n)) {
		cnt += n * n;
		return;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			check(x + i * n / 2, y + j * n / 2, n / 2);
		}
	}


}

int main() {
	cin >> n >> r >> c;

	check(0, 0, jegob(n));

}