#include "pch.h"
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int visit[21];
int map[21][21];
int n;
int ans = INT_MAX;

void go() {
	int num1 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i] && visit[j]) {
				num1 += map[i][j];
			}
		}
	}

	int num2 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit[i] && !visit[j]) {
				num2 += map[i][j];
			}
		}
	}

	ans = min(ans, abs(num1 - num2));
	return;
}

void solve(int index, int cnt) {
	if (cnt == n / 2) {
		go();
		return;
	}

	if (index == n + 1) return;

	visit[index] = true;
	solve(index + 1, cnt + 1);
	visit[index] = false;
	solve(index + 1, cnt);
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	solve(1, 0);
	cout << ans << '\n';
}

