#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int st, en;
vector<pair<int, int>> v[100001];
int a[100001];

bool check(int st, int mid) {
	if (a[st]) return false;

	a[st] = true;
	if (st == en) return true;

	for (auto &p : v[st]) {
		int next = p.first;
		int cost = p.second;
		if (cost >= mid) {
			if (check(next, mid)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	cin >> st >> en;

	int left = 1;
	int right = 1000000000;
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		memset(a, 0, sizeof(a));

		if (check(st, mid)) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans << '\n';
}