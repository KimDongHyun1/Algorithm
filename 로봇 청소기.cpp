#include "pch.h"
#include <iostream>
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int a[52][52];
int n, m, x, y, d, flag, cnt;

int main() {
	cin >> n >> m;
	cin >> x >> y >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {
		if (!a[x][y]) {
			cnt++;
			a[x][y] = 2;
		}

		for (int i = 0; i < 5; i++) {
			if (i == 4) { // 후진
				int nd = (d + 2) % 4;
				int nx = x + dx[nd];
				int ny = y + dy[nd];
				

				if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || a[nx][ny] == 1) { // 벽 이면 끝
					flag = 1;
				}
				else {
					x = nx;
					y = ny;
				}
				break;
			}
			int nd = (d + 3) % 4;
			int nx = x + dx[nd];
			int ny = y + dy[nd];
			if (nx < 0 || nx > n-1 || ny < 0 || ny > m-1 || !a[nx][ny]) {
				d = nd;
				x = nx;
				y = ny;
				break;
			}
			else {
				d = nd;
			}
		}
		if (flag) break;
	}
	cout << cnt << '\n';
	return 0;
}