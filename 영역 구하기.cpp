#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool visited[101][101];
int a[101][101];
int m, n, k;

int bfs(int i, int j) {
	int count = 1;
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

			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (!visited[nx][ny] && !a[nx][ny]) {
					count++;
					visited[nx][ny] = true;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}

	return count;
}

int main()
{
	cin >> m >> n >> k;

	for (int cnt = 0; cnt < k; cnt++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				a[i][j] = true;
			}
		}
	}

	vector<int> v;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && !a[i][j]) {
				v.push_back(bfs(i, j));
			}
		}
	}
	
	cout << v.size() << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
	return 0;
	
}

