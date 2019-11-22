#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>
#include <queue>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int visited[101][101];
int a[101][101];
int n, cnt, sum, num;
int ans = INT_MAX;

void bfs(int i, int j) {
	queue<pair<int, int>> Q;
	Q.push(make_pair(i, j));
	a[i][j] = cnt;
	visited[i][j] = true;

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (a[nx][ny] && !visited[nx][ny]) {
					a[nx][ny] = cnt;
					visited[nx][ny] = true;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}

}

void bfs2(int i, int j) {

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
				if (!visited[nx][ny] && !a[nx][ny]) {
					visited[nx][ny] = visited[x][y] + 1;
					Q.push(make_pair(nx, ny));
				}

				if (a[nx][ny] > 0 && a[nx][ny] != num) {
					ans = min(ans, visited[x][y]);
					return;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] & !visited[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			num = a[i][j];
			memset(visited, 0, sizeof(visited));
			if (a[i][j] > 0) bfs2(i, j);
		}
	}

	cout << ans << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}

