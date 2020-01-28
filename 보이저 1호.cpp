#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
char map[501][501];
int n, m, r, c, cnt, ans;
char ch;

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j + 1] = s[j];
		}
	}
	cin >> r >> c;

	for (int k = 0; k < 4; k++) {

		cnt = 1;

		int x = r + dx[k];
		int y = c + dy[k];
		int dir = k;
		//cout << k << " Start : " << x << " , " << y << ' ' << map[x][y] << '\n';

		while (true) {
			if (x <= 0 || x > n || y <= 0 || y > m || map[x][y] == 'C') {
				if (ans < cnt) {
					ans = cnt;
					if (k == 0) ch = 'U';
					if (k == 1) ch = 'R';
					if (k == 2) ch = 'D';
					if (k == 3) ch = 'L';
				}
				//cout << k << ' ' << cnt << '\n';
				break;
			}

			//cout << k << " : " << x << ' ' << y << ' ' << map[x][y] << '\n';
			// 북 동 남 서
			if (map[x][y] == '/') {
				if (dir == 0) dir = 1;
				else if (dir == 1) dir = 0;
				else if (dir == 2) dir = 3;
				else if (dir == 3) dir = 2;
			}

			if (map[x][y] == '\\') {
				if (dir == 0) dir = 3;
				else if (dir == 1) dir = 2;
				else if (dir == 2) dir = 1;
				else if (dir == 3) dir = 0;
			}

			if (x == r && y == c) {
				if (x == r && y == c && dir == k) {
					if (k == 0) cout << 'U' << '\n';
					else if (k == 1) cout << 'R' << '\n';
					else if (k == 2) cout << 'D' << '\n';
					else if (k == 3) cout << 'L' << '\n';
					cout << "Voyager" << '\n';
					return 0;
				}

			}


			x += dx[dir];
			y += dy[dir];
			cnt++;
		}
	}

	cout << ch << '\n';
	cout << ans << '\n';

	return 0;
}