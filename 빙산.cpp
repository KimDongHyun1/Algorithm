#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int visit[301][301];
int a[301][301];
int b[301][301];
int N, M, cnt, ans; 

void bfs(int i, int j) {
	visit[i][j] = true;
	queue<pair<int, int>> Q;
	Q.push({ i,j });

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < N && nx >= 0 && ny < M && a[nx][ny]>0 && !visit[nx][ny]) {
				visit[nx][ny] = true;
				Q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}

	while(true) {
		memset(b, 0, sizeof(b));
		memset(visit, 0, sizeof(visit));
		cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j] > 0 && !visit[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt >= 2) {
			cout << ans << '\n';
			return 0;
		}

		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j] <= 0) cnt++;
			}
		}
		if (cnt == N * M) {
			cout << 0 << '\n';
			return 0;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j]) {
					cnt = 0;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx >= 0 && nx < N && ny >= 0 && ny < M && a[nx][ny]<=0) cnt++;
					}
					b[i][j] += cnt;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				a[i][j] = a[i][j] - b[i][j];
			}
		}

		ans++;
	}

}
