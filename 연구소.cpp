#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m, ans;
int a[8][8];
int visited[8][8];
vector<pair<int, int>> virus;


// 배운거
// bfs에서 새로 만들어서 안하면 visited에 true들이 생겨서 
// check에서 활동하는데 방해할 수 있음
// bfs에서는 true된거를 false 안해주기 때문
void copy(int(*a)[8], int(*b)[8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void bfs() {
	int spread[8][8];
	copy(spread, visited);
	queue<pair<int, int>> Q;
	for (int i = 0; i < virus.size(); i++) {
		Q.push({ virus[i].first, virus[i].second });
	}

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!spread[nx][ny]) {
					spread[nx][ny] = 2;
					Q.push({ nx,ny });
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!spread[i][j]) cnt++;
		}
	}

	ans = max(ans, cnt);
	return;
}

void check(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				visited[i][j] = 1;
				check(cnt + 1);
				visited[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			
			visited[i][j] = a[i][j];

			if (a[i][j] == 2) virus.push_back({ i,j });
		}
	}

	check(0);

	cout << ans << '\n';
}