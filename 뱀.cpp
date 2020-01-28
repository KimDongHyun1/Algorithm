#include "pch.h"
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
int dx[] = { 0,1,0,-1 }; // 동 남 서 북
int dy[] = { 1,0,-1,0 };
int visit[101][101];
int map[101][101];
char Time[10001];
int N, K, X, Y, L, A, ans;
int sx, sy, fx, fy, nx, ny;
char B;

int main()
{
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> X >> Y;
		map[X][Y] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> A >> B;
		Time[A] = B;
	}

	deque<pair<int, int>> D;
	D.push_front({ 1,1 });
	visit[1][1] = true;
	int d = 0;

	while (true) {
		ans++;
		// 동 남 서 북
		if (Time[ans - 1] == 'D') d = (d + 1) % 4;
		else if(Time[ans - 1] == 'L') d = (d + 3) % 4;
		
		sx = D.front().first;
		sy = D.front().second;
		fx = D.back().first;
		fy = D.back().second;
		nx = sx + dx[d];
		ny = sy + dy[d];

		if (nx <= 0 || nx > N || ny <= 0 || ny > N || visit[nx][ny]) {
			cout << ans << '\n';
			return 0;
		}

		visit[nx][ny] = true;
		D.push_front({ nx,ny });
		if (!map[nx][ny]) {
			D.pop_back();
			visit[fx][fy] = false;
		}

		if (map[nx][ny]) map[nx][ny] = 0;
		//cout << D.front().first << ' ' << D.front().second << '\n';
	}

	cout << ans << '\n';
	return 0;
}
