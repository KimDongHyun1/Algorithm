#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int r, c;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int check(vector<string> &s, vector<bool> &alpha, int row, int col) {
	int ans = 0;

	for (int k = 0; k < 4; k++) {
		int nx = row + dx[k];
		int ny = col + dy[k];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c && !alpha[s[nx][ny] - 'A']) {
			alpha[s[nx][ny] - 'A'] = true;
			int plus = check(s, alpha, nx, ny);
			alpha[s[nx][ny] - 'A'] = false;
			if (plus > ans) ans = plus;
		}
	}

	return ans + 1;
}

int main() {
	cin >> r >> c;
	vector<string> s(r);
	for (int i = 0; i < r; i++) {
		cin >> s[i];
	}

	vector<bool> alpha(26);
	alpha[s[0][0] - 'A'] = true;
	cout << check(s, alpha, 0, 0) << '\n';
	return 0;
}
