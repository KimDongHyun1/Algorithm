#include "pch.h"
#include <iostream>
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int a[50][50];
int n, m, x, y, d, cnt, flag, nd, nx, ny;

int main()
{
	cin >> n >> m;
	cin >> x >> y >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	while (true) {
		if (!a[x][y]) {
			a[x][y] = 2;
			cnt++;
		}

		bool flag = false;
		for (int k = 0; k < 4; k++) {
			nd = (d + 3) % 4;
			nx = x + dx[nd];
			ny = y + dy[nd];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !a[nx][ny]) {
				x = nx;
				y = ny;
				d = nd;
				flag = true;
				break;
			}
			else {
				d = nd;
			}
		}
		if (flag) continue;

		nd = (d + 2) % 4;
		nx = x + dx[nd];
		ny = y + dy[nd];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == 1) break;

		x = nx;
		y = ny;
	}

	cout << cnt << '\n';
	return 0;
}

