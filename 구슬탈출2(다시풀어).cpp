#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#define SIZE 12
using namespace std;
struct point {
	int rx, ry, bx, by;
};

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool visit[SIZE][SIZE][SIZE][SIZE];
char a[SIZE][SIZE];
int N, M, ans, cnt;
int rx, ry, bx, by;
int orx, ory, obx, oby;
int nrx, nry, nbx, nby;
queue<point> Q;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		for (int j = 0; j < M; j++) {
			if (a[i][j] == 'R') {
				rx = i;
				ry = j;
				a[i][j] = '.';
			}
			if (a[i][j] == 'B') {
				bx = i;
				by = j;
				a[i][j] = '.';
			}
		}
	}
}

void bfs() {
	while (!Q.empty()) {
		int size = Q.size();
		
		while (size--) {
			orx = Q.front().rx;
			ory = Q.front().ry;
			obx = Q.front().bx;
			oby = Q.front().by;
			Q.pop();

			if (a[orx][ory] == 'O' && a[obx][oby] != 'O') {
				ans = cnt;
				return;
			}

			for (int k = 0; k < 4; k++) {
				rx = orx;
				ry = ory;
				bx = obx;
				by = oby;


				while (true) {
					nrx = rx + dx[k];
					nry = ry + dy[k];
					if (a[nrx][nry] == '#' || a[rx][ry] == 'O') break;
					rx = nrx;
					ry = nry;
				}

				while (true) {
					nbx = bx + dx[k];
					nby = by + dy[k];
					if (a[nbx][nby] == '#' || a[bx][by] == 'O') break;
					bx = nbx;
					by = nby;
				}

				if (rx == bx && ry == by) {
					if (a[bx][by] == 'O') continue;
					if (abs(orx - rx) + abs(ory - ry) > abs(obx - bx) + abs(oby - by)) {
						rx -= dx[k];
						ry -= dy[k];
					}
					else {
						bx -= dx[k];
						by -= dy[k];
					}
				}

				if (visit[rx][ry][bx][by]) continue;
				visit[rx][ry][bx][by] = true;
				Q.push({ rx,ry,bx,by });
			}
		}
		if (cnt == 10) {
			ans = -1;
			return;
		}
		cnt++;

	}
	ans = -1;
	return;

}

void solve() {
	visit[rx][ry][bx][by] = true;
	Q.push({ rx,ry,bx,by });
	bfs();
}

int main() {
	input();
	solve();
	cout << ans << '\n';
	return 0;
}