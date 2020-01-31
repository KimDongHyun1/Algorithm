#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dx[] = { -1,-2,-2,-1,1,2,2,1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };
int map[1001][1001];
int visit[1001][1001];
int n, m, q, k, p, x, y, a, b;
queue<pair<int, int>> Q;
queue<pair<int, int>> K;

int main(void) {
	cin >> n >> m;

	cin >> q;
	while (q--) {
		cin >> x >> y;
		Q.push({ x,y });
		map[x][y] = 1;
		visit[x][y] = 1;
	}

	cin >> k;
	while (k--) {
		cin >> x >> y;
		K.push({ x,y });
		map[x][y] = 1;
		visit[x][y] = 1;
	}

	cin >> p;
	while (p--) {
		cin >> x >> y;
		map[x][y] = 1;
		visit[x][y] = 1;
	}

	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();

		// 가로 왼, 오
		for (int mid = y - 1; mid >= 1; mid--) {
			if (map[x][mid] == 0) visit[x][mid] = 1;
			else break;
		}
		for (int mid = y + 1; mid <= m; mid++) {
			if (map[x][mid] == 0) visit[x][mid] = 1;
			else break;
		}
		// 세로
		for (int mid = x - 1; mid >= 1; mid--) {
			if (map[mid][y] == 0) visit[mid][y] = 1;
			else break;
		}
		for (int mid = x + 1; mid <= n; mid++) {
			if (map[mid][y] == 0) visit[mid][y] = 1;
			else break;
		}

		// 대각 좌상, 좌하, 우상, 우하
		a = x;
		b = y;
		while (true) {
			a -= 1;
			b -= 1;
			if (a <= 0 || a > n || b <= 0 || b > m || map[a][b]) break;
			visit[a][b] = 1;
		}

		a = x;
		b = y;
		while (true) {
			a += 1;
			b -= 1;
			if (a <= 0 || a > n || b <= 0 || b > m || map[a][b]) break;
			visit[a][b] = 1;
		}

		a = x;
		b = y;
		while (true) {
			a -= 1;
			b += 1;
			if (a <= 0 || a > n || b <= 0 || b > m || map[a][b]) break;
			visit[a][b] = 1;
		}

		a = x;
		b = y;
		while (true) {
			a += 1;
			b += 1;
			if (a <= 0 || a > n || b <= 0 || b > m || map[a][b]) break;
			visit[a][b] = 1;
		}

	}

	while (!K.empty()) {
		x = K.front().first;
		y = K.front().second;
		K.pop();

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
			}
		}

	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j] == 0) ans++;
		}
	}

	cout << ans << '\n';
	return 0;
}