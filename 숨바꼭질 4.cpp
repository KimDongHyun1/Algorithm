#include "pch.h"
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
int visited[100001];
int n, k;
int cnt = 0;

int main()
{
	cin >> n >> k;

	queue<int> Q;
	Q.push(n);
	memset(visited, -1, sizeof(visited));
	visited[n] = n;

	while (!Q.empty()) {
		int size = Q.size();

		while (size--) {
			int x = Q.front();
			Q.pop();

			if (x == k) {
				cout << cnt << '\n';
				int pre = k;
				stack<int> S;
				while (pre != n) {
					S.push(pre);
					pre = visited[pre];
				}

				cout << n << ' ';
				while (!S.empty()) {
					cout << S.top() << ' ';
					S.pop();
				}

				return 0;
			}

			if (x * 2 <= 100000 && visited[x * 2] == -1) {
				visited[x * 2] = x;
				Q.push(x * 2);
			}
			if (x + 1 <= 100000 && visited[x + 1] == -1) {
				visited[x + 1] = x;
				Q.push(x + 1);
			}
			if (x - 1 >= 0 && visited[x - 1] == -1) {
				visited[x - 1] = x;
				Q.push(x - 1);
			}
		}
		cnt++;

	}
}

