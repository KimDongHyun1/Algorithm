#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int visit[12][6];
char map[12][6];
vector<pair<int, int>> Boom_Tmp, Boom_Vec;
int ans, Boom_Cnt, Temp_Cnt;
bool Flag;

void DFS(int x, int y) {
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6 && !visit[nx][ny] && map[nx][ny] == map[x][y]) {
			Temp_Cnt++;
			visit[nx][ny] = true;
			Boom_Tmp.push_back(make_pair(nx, ny));
			DFS(nx, ny);
		}

		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int i = 0; i < 12; i++) {
		cin >> map[i];
	}


	while (true) {
		Flag = false;
		memset(visit, 0, sizeof(visit));
		Boom_Vec.clear();

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && !visit[i][j]) {
					Temp_Cnt = 1;
					Boom_Tmp.push_back({ i,j });
					visit[i][j] = true;
					DFS(i, j);

					if (Temp_Cnt >= 4) {
						Flag = true;
						for (int i = 0; i < Boom_Tmp.size(); i++) {
							Boom_Vec.push_back(Boom_Tmp[i]);
						}
					}
					Boom_Tmp.clear();
				}
			}
		}
		for (int i = 0; i < Boom_Vec.size(); i++) {
			int x = Boom_Vec[i].first;
			int y = Boom_Vec[i].second;

			map[x][y] = '.';
		}

		for (int i = 10; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] == '.') continue;
				int Tmp = i;

				while (true) {
					if (Tmp == 11 || map[Tmp + 1][j] != '.') break;

					map[Tmp + 1][j] = map[Tmp][j];
					map[Tmp][j] = '.';
					Tmp++;
				}

			}
		}

		if (Flag == true) ans++;
		else break;
	}
	cout << ans << '\n';
}

