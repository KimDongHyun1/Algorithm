#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[1000][1000];

void append(string &s, char c, int cnt) {
	for (int i = 0; i < cnt; i++) {
		s += c;
	}
}

int main() {
	int n, m;
	string s = "";
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	//행or열 둘 중 하나가 홀수일 경우
	if (n % 2 == 1) {
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				append(s, 'R', m - 1);
				if (i != n - 1) {
					append(s, 'D', 1);
				}
			}
			else {
				append(s, 'L', m - 1);
				append(s, 'D', 1);
			}
		}
	}
	else if (m % 2 == 1) {
		for (int j = 0; j < m; j++) {
			if (j % 2 == 0) {
				append(s, 'D', n - 1);
				if (j != m - 1) {
					append(s, 'R', 1);
				}
			}
			else {
				append(s, 'U', n - 1);
				append(s, 'R', 1);
			}
		}
	} // 행,렬 둘 다 짝수일 경우
	else {
		int x, y; // 최소값을 구할 때, 체스판처럼 생각해야함. 
		x = 0;
		y = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i + j) % 2 == 1) {
					if (a[x][y] > a[i][j]) {
						x = i;
						y = j;
					}
				}
			}
		}

		//(0,0) 과 (n-1,m-1)로 왔다갔다
		int x1 = 0;
		int y1 = 0;
		int x2 = n - 1;
		int y2 = m - 1;
		string s2 = "";
		while (x2 - x1 > 1) {
			if (x1 < x - 1) {
				append(s, 'R', m - 1);
				append(s, 'D', 1);
				append(s, 'L', m - 1);
				append(s, 'D', 1);
				x1 += 2;
			}
			if (x < x2 - 1) {
				append(s2, 'R', m - 1);
				append(s2, 'D', 1);
				append(s2, 'L', m - 1);
				append(s2, 'D', 1);
				x2 -= 2;
			}
		}

		while (y2 - y1 > 1) {
			if (y1 < y - 1) {
				append(s, 'D', 1);
				append(s, 'R', 1);
				append(s, 'U', 1);
				append(s, 'R', 1);
				y1 += 2;
			}
			if (y < y2 - 1) {
				append(s2, 'D', 1);
				append(s2, 'R', 1);
				append(s2, 'U', 1);
				append(s2, 'R', 1);
				y2 -= 2;
			}
		}


		if (y == y1) {
			append(s, 'R', 1);
			append(s, 'D', 1);
		}
		else {
			append(s, 'D', 1);
			append(s, 'R', 1);
		}
		reverse(s2.begin(), s2.end());
		s += s2;
	}
	cout << s << '\n';
	return 0;
}