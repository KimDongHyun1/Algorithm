#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool visited[50][50];
char a[50][50];
int n, m;
int ans = 0;

int bfs(int i, int j) {
	visited[i][j] = true;
	queue<pair<int, int>> Q;
	Q.push(make_pair(i, j));

	int cnt = -1;
	while (!Q.empty()) {
		int size = Q.size();

		while (size--) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (!visited[nx][ny] && a[nx][ny] == 'L') {
						visited[nx][ny] = true;
						Q.push(make_pair(nx, ny));
					}
				}
			}
		}

		cnt++;
	}

	return cnt;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, 0, sizeof(visited));
			if (a[i][j] == 'L') {
				ans = max(ans, bfs(i, j));
			}
		}
	}

	cout << ans << '\n';
}
