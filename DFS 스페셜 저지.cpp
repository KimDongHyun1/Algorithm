#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool visit[100001];
int order[100001];
vector<int> v[100001];
vector<int> d;
vector<int> ans;
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
		ans.push_back(x);
		order[x] = i; // ans 의 우선순위 !! ㅁ<-ㅁ <-ㅁ <-ㅁ
	}

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end(), [](const int &u, const int &v) {
			return order[u] < order[v];
		});
	}
	
	DFS(1);

	bool check = true;
	for (int i = 0; i < n; i++) {
		if (ans[i] != d[i]) {
			check = false;
			break;
		}
	}

	cout << check << '\n';
	return 0;
}

