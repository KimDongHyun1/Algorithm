#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string a[20];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;

int check(int step, int x1, int y1, int x2, int y2) {
	if (step == 11) return -1;
	bool one = false;
	bool two = false;
	if (x1<0 || x1>=n || y1<0 || y1>=m) one = true;
	if (x2<0 || x2>=n || y2<0 || y2>=m) two = true;
	if (one && two) return -1;
	if (one || two) return step;
	int ans = -1;

	for (int i = 0; i < 4; i++) {
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		int nx2 = x2 + dx[i];
		int ny2 = y2 + dy[i];

		if (nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < m && a[nx1][ny1] == '#') {
			nx1 = x1;
			ny1 = y1;
		}
		if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m && a[nx2][ny2] == '#') {
			nx2 = x2;
			ny2 = y2;
		}

		int sum = check(step + 1, nx1, ny1, nx2, ny2);
		if (sum == -1) continue;
		if (ans == -1 || ans > sum) ans = sum;
	}
	return ans;
}

int main() {
	cin >> n >> m;
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'o') {
				if (x1 == -1) {
					x1 = i;
					y1 = j;
				}
				else {
					x2 = i;
					y2 = j;
				}
			}
		}
	}

	cout << check(0, x1, y1, x2, y2) << '\n';
	return 0;

}