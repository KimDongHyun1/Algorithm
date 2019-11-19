#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000][1000];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n, num, x, y, nx, ny, k, i;
int ansX, ansY;

int main()
{
	cin >> n >> num;
	i = n * n;

	while (i) {
		a[x][y] = i--;


		if (a[x][y] == num) {
			ansX = x + 1;
			ansY = y + 1;
		}

		nx = x + dx[k];
		ny = y + dy[k];
		if (nx<0 || nx>=n || ny<0 || ny>=n || a[nx][ny]) {
			k = (k + 1) % 4;

			x = x + dx[k];
			y = y + dy[k];
		}
		else {
			x = nx;
			y = ny;
		}
		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << ansX << ' ' << ansY << '\n';
	return 0;
}
