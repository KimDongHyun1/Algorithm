#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[100001];
vector<int> d;
int visit[100001];
int order[100001];
int arr[100001];
int n;

void DFS(int x) {
	visit[x] = true;
	d.push_back(x);

	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (!visit[y]) {
			DFS(y);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
		order[x] = i;
	}

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end(), [](const int &u, const int &v) {
			return order[u] < order[v];
		});
	}

	DFS(1);
	for (int i = 0; i < n; i++) {
		if (arr[i] != d[i]) {
			cout << 0 << '\n';
			return 0;
		}
	}

	cout << 1 << '\n';
	return 0;
}

