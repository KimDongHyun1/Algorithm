#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int dice[7] = { 0,0,0,0,0,0,0 };
int map[21][21];
int dx[] = { 0, 0,0,-1,1 }; // 동 서 북 남
int dy[] = { 0, 1,-1,0,0 };
int n, m, x, y, k, dir, temp1, temp2;

void output() {
	if (map[x][y]) {
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
	else {
		map[x][y] = dice[6];
	}
	cout << dice[1] << '\n';

	/*for (int i = 1; i <= 6; i++) cout << dice[i] << ' ';
	cout << '\n';
*/
	return;
}

int main(void) {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	
	while (k--) {
		cin >> dir;
		if (x + dx[dir] < 0 || x + dx[dir] >= n || y + dy[dir] < 0 || y + dy[dir] >= m) continue;

		x += dx[dir];
		y += dy[dir];
		
		if (dir == 1) {
			temp1 = dice[4];
			temp2 = dice[1];

			dice[4] = dice[6];
			dice[1] = temp1;

			temp1 = dice[3];

			dice[3] = temp2;
			dice[6] = temp1;

			output();
		}
		else if (dir == 2) {
			temp1 = dice[3];
			temp2 = dice[1];

			dice[3] = dice[6];
			dice[1] = temp1;

			temp1 = dice[4];

			dice[4] = temp2;
			dice[6] = temp1;

			output();
		}
		else if (dir == 3) {
			temp1 = dice[5];
			temp2 = dice[1];

			dice[5] = dice[6];
			dice[1] = temp1;

			temp1 = dice[2];

			dice[2] = temp2;
			dice[6] = temp1;

			output();
		}
		else if (dir == 4) {
			temp1 = dice[2];
			temp2 = dice[1];

			dice[2] = dice[6];
			dice[1] = temp1;
			
			temp1 = dice[5];
			
			dice[5] = temp2;
			dice[6] = temp1;

			/*
			dice[2] = dice[6];
			dice[1] = dice[2];
			dice[5] = dice[1];
			dice[6] = dice[5];*/

			output();
		}
	}
}