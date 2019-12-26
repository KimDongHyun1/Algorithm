#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool visit[51][51];
char map[51][51];
int R, C, cnt;
queue<pair<int, int>> Q;
queue<pair<int, int>> water;
 
int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'S') {
				Q.push({ i,j });
			}
			if (map[i][j] == '*') {
				water.push({ i,j });
			}
		}
	}

	while (!Q.empty()) {
		int size = water.size();
		while (size--) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx >= 0 && nx < R && ny >= 0 && ny < C && map[nx][ny] != 'X' && map[nx][ny] != 'D' && map[nx][ny] != '*') {
					water.push({ nx,ny });
					map[nx][ny] = '*';
				}
			}
		}

		size = Q.size();
		while (size--) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();

			if (map[x][y] == 'D') {
				cout << cnt << '\n';
				return 0;
			}

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx >= 0 && nx < R && ny >= 0 && ny < C && map[nx][ny] != 'X' && map[nx][ny] != '*' && !visit[nx][ny]) {
					visit[nx][ny] = true;
					Q.push({ nx,ny });
				}
			}
		}
		cnt++;
	}

	cout << "KAKTUS" << '\n';
}
