#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int a[501][501];
int visited[501][501];
int n, ans;
	
int dfs(int x, int y) {
	if (visited[x][y]) return visited[x][y];

	visited[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n && a[x][y] < a[nx][ny]) {
			visited[x][y] = max(visited[x][y], dfs(nx, ny) + 1);
		}
	}


	return visited[x][y];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				ans = max(ans, dfs(i, j));
			}
		}
	}

	cout << ans << '\n';
	return 0;
}

