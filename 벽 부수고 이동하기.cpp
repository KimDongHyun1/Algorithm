#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int visited[1001][1001][2];
int a[1001][1001];
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			int temp = s[j] - '0';
			a[i][j] = temp;
		}
	}

	queue<pair<pair<int, int>, pair<int, int>>> Q;
	Q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	visited[0][0][0] = 1; // 3번째에 0은 안부셨을때 1은 부셨을때 같음

	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int B = Q.front().second.first; // 벽 안부심0 , 부심1
		int Cnt = Q.front().second.second;
		Q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << Cnt << '\n';
			return 0;
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
				if (a[nx][ny] && B == 0) { // 막혔는대 찬스 안썻으면,
					visited[nx][ny][B + 1] = true;
					Q.push(make_pair(make_pair(nx, ny), make_pair(B + 1, Cnt + 1)));
				}
				else if (!a[nx][ny] && !visited[nx][ny][B]) {
					visited[nx][ny][B] = true;
					Q.push(make_pair(make_pair(nx, ny), make_pair(B, Cnt + 1)));
				}
			}
		}
	}

	cout << -1 << '\n';
	return 0;
}
