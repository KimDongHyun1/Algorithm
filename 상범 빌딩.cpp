#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
int dz[] = { 0,0,0,0,1,-1 };
int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int visit[31][31][31];
char map[31][31][31];
int L, R, C, sz, sx, sy, cnt;

int main()
{
	while (true) {
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
		bool Flag = false;
		cnt = 0;
		cin >> L >> R >> C;
		
		if (L == R  && R == C  && C == 0) return 0;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				string s;
				cin >> s;
				for (int k = 0; k < s.size(); k++) {
					map[i][j][k] = s[k];
					if (map[i][j][k] == 'S') {
						sz = i;
						sx = j;
						sy = k;
					}
				}
			}
		}

		queue<pair<int, pair<int, int>>> Q;
		Q.push({ sz,{sx,sy} });

		while (!Q.empty()) {
			int size = Q.size();

			while (size--) {
				int z = Q.front().first;
				int x = Q.front().second.first;
				int y = Q.front().second.second;
				Q.pop();

				if (map[z][x][y] == 'E') {
					Flag = true;
					break;
				}

				for (int k = 0; k < 6; k++) {
					int nz = z + dz[k];
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nz >= 0 && nz < L && nx >= 0 && nx < R && ny >= 0 && ny < C && !visit[nz][nx][ny]) {
						if ((map[nz][nx][ny] == '.' || map[nz][nx][ny] == 'E')) {
							visit[nz][nx][ny] = true;
							Q.push({ nz,{nx,ny} });
						}
					}
				}
			}
			if (Flag) break;
			cnt++;
		}
		if(Flag) cout << "Escaped in " << cnt << " minute(s)." << '\n';
		else cout << "Trapped!" << '\n';
	}

	return 0;
}

