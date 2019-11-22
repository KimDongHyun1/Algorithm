#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool visited[100001];
bool finished[100001];
int a[100001];
int t, n, cnt;

void dfs(int cur) {
	visited[cur] = true;
	int next = a[cur];

	if (!visited[next]) {
		dfs(next);
	}
	else if (visited[next] && !finished[next]) {
		for (int i = next; i != cur; i = a[i]) {
			cnt++;
		}
		cnt++;
	}

	finished[cur] = true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;

		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		memset(a, 0, sizeof(a));
		cnt = 0;

		for (int i = 1; i <= n; i++) cin >> a[i];

		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				dfs(i);
		}

		cout << n - cnt << '\n';
	}

	return 0;
}

