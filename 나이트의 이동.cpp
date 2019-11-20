#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int dx[] = { -2,-1,1,2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };
int visited[301][301];
int a[301][301];
int n, startX, startY, endX, endY;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		memset(visited, 0, sizeof(visited));

		cin >> n;
		cin >> startX >> startY;
		cin >> endX >> endY;
		queue<pair<int, int>> Q;
		Q.push(make_pair(startX, startY));

		while (!Q.empty()) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();

			if (x == endX && y == endY) {
				cout << visited[x][y] << '\n';
				break;
			}

			for (int k = 0; k < 8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (!visited[nx][ny]) {
						visited[nx][ny] = visited[x][y] + 1;
						Q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}

	return 0;
}

