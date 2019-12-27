#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int visit[10001];
bool check[10001];
int N, x, y, k, ans;
vector<pair<int,int>> v[10001];


void bfs(int x) {
	visit[x] = true;
	queue<int> Q;
	Q.push(x);

	while (!Q.empty()) {
		x = Q.front();
		Q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			y = v[x][i].first;
			if (!visit[y]) {
				visit[y] = visit[x] + v[x][i].second;
				Q.push(y);
			}
		}
	}

	for (int j = 1; j <= N; j++) {
		ans = max(ans, visit[j] - 1);
	}
	
	
}

int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y >> k;
		v[x].push_back({ y, k });
		v[y].push_back({ x,k });

		check[x] = false;
		check[y] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (check[i]) {
			memset(visit, 0, sizeof(visit));
			bfs(i);

			
		}
	}

	cout << ans << '\n';
	return 0;
}

