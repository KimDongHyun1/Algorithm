#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int visit[101];
bool a[101][101];
int N, X, Y, M;
int ans = -1;
queue<int> Q;   

int main()
{
	cin >> N;
	cin >> X >> Y;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = true;
	}

	Q.push(X);
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		if (x == Y) {
			ans = visit[x];
			break;
		}

		for (int y = 1; y <= N; y++) {
			if (!visit[y] && a[x][y]) {
				visit[y] = visit[x] + 1;
				Q.push(y);
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
