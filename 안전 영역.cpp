#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <cstring>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int a[101][101];
bool visited[101][101];
int n; int small = INT_MAX; int big = INT_MIN;
int ans = 0;

void bfs(int i, int j) {
	visited[i][j] = true;
	queue<pair<int, int>> Q;
	Q.push(make_pair(i, j));

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			big = max(big, a[i][j]);
			small = min(small, a[i][j]);
		}
	}

	for (int k = 0; k <= big; k++) {
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] <= k) {
					visited[i][j] = true;
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans << '\n';
}

