#include "pch.h"
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int a[101][101];
int visited[101];
bool ans[101][101];
int n;

bool bfs(int start, int end) {
	memset(visited, 0, sizeof(visited));
	// visited[start] = true; 빼놔야지 start랑 end가 같아도 됨
	queue<int> Q;
	Q.push(start);

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
	
		for (int next = 0; next < n; next++) {
			if (!visited[next] && a[now][next]) {
				visited[next] = true;
				Q.push(next);

				if (next == end) return true;
			}
		}
	}

	return false;
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
			ans[i][j] = bfs(i, j);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}