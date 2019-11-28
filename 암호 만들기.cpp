#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char a[16];
int L, C;
bool check; // false이면 자음, true이면 모음
vector<char> v;

void dfs(int index, int cnt, int mo, int ja) {
	if (cnt == L && mo>=1 && ja>=2) {
		for (int i = 0; i < L; i++) {
			cout << v[i];
		}
		cout << '\n';
		return;
	}

	if (index > C - 1) return;

	check = false;
	if (a[index] == 'a' || a[index] == 'e' || a[index] == 'i' || a[index] == 'o' || a[index] == 'u') check = true;

	v.push_back(a[index]);
	if (check) {
		dfs(index + 1, cnt + 1, mo + 1, ja);
	}
	else {
		dfs(index + 1, cnt + 1, mo, ja + 1);
	}
	v.pop_back();
	if (check) {
		dfs(index + 1, cnt, mo, ja);
	}
	else {
		dfs(index + 1, cnt, mo, ja);
	}
}

int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> a[i];

	sort(a, a + C);
	dfs(0, 0, 0, 0);
}
