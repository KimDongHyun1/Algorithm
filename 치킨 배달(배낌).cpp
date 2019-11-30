#include "pch.h"
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int a[50][50];
int b[50][50];
vector<pair<int, int>> home; // 집 다 넣기
vector<pair<int, int>> chicken; // 치킨집 다 넣기 
vector<pair<int, int>> check;
int n, m;
int ans = INT_MAX;

void dfs(int index, int cnt) {
	if (cnt == m) {
		int sum = 0;
		for (int i = 0; i < home.size(); i++) {
			int small = INT_MAX;
			for (int j = 0; j < check.size(); j++) {
				int temp = abs(home[i].first - check[j].first) + abs(home[i].second - check[j].second);
				if (small > temp) small = temp;
			}
			sum += small;
		}
		if (ans > sum) ans = sum;
		return;
	}

	if (index > chicken.size()-1) return;

	check.push_back({ chicken[index].first, chicken[index].second });
	dfs(index + 1, cnt + 1);
	check.pop_back();
	dfs(index + 1, cnt);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				home.push_back({ i,j });
			}
			if (a[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}
