#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int visit[3001];
int cycle[3001];
int map[3001][3001];
int n, x, y;
int check;

void DFS(int x, int pre) {
	
	for (int y = 1; y <= n; y++) {
		if (map[x][y] && y != pre && visit[y]!=2) {
			visit[y]++;
			if (visit[y]==2) {
				check = y;
				return;
			}
			DFS(y, x);
		}
	}
}

void DFS_2(int x, int pre, int start) {
	if (visit[start]) {
		for (int i = 1; i <= n; i++) {
			cycle[i] = visit[i];
		}
		return;
	}

	for (int y = 1; y <= n; y++) {
		if (!visit[y] && map[x][y] && pre != y) {
			visit[y] = true;
			DFS_2(y, x, start);
			visit[y] = false;
		}
	}
}

void BFS() {
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		if (cycle[i]) {
			Q.push(i);
			visit[i] = 0;
			break;
		}
	}

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		for (int y = 1; y <= n; y++) {
			if (visit[y] == -1 && map[x][y]) {
				if (cycle[y]) {
					visit[y] = 0;
					Q.push(y);
				}
				else {
					visit[y] = visit[x] + 1;
					Q.push(y);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}

	visit[1] = 1;
	DFS(1, 1);
	
	memset(visit, 0, sizeof(visit));
	DFS_2(check, check, check);

	memset(visit, -1, sizeof(visit));
	BFS();

	for (int i = 1; i <= n; i++) cout << visit[i] << ' ';
	cout << '\n';
	return 0;
}

