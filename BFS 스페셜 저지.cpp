#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int visit[100001];
int arr[100001];
int index = 1;
int ans = 1;
int n;
vector<int> v[100001];

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 0; i < n; i++) cin >> arr[i];

	queue<int> Q;
	Q.push(1);
	visit[1] = true;

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		priority_queue<int> q1;
		priority_queue<int> q2;
		int cnt = 0;

		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!visit[y]) {
				cnt++;
				q1.push(y);
			}
		}
		
		for (int i = index; i < index + cnt; i++) {
			q2.push(arr[i]);
		}

		while (!q1.empty()) {
			if (q1.top() != q2.top()) {
				ans = 0;
				break;
			}

			q1.pop();
			q2.pop();
		}

		if (ans == 0) break;

		for (int i = index; i < index + cnt; i++) {
			visit[arr[i]] = true;
			Q.push(arr[i]);
		}

		index += cnt;
	}

	cout << ans << '\n';
	return 0;
}
