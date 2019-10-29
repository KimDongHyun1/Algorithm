#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	char a[50][50];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 50 * 50;
	for (int x = 0; x <= n - 8; x++) {
		for (int y = 0; y <= m - 8; y++) {

			// 여기서 cnt1과 cnt2를 해놓은 이유는
			// 시작하는 (x,y)가 'B'나'W' 라고해서 나중에도 그게 더 많지 않을 수 있기 떄문이다.
			int cnt1 = 0;
			int cnt2 = 0;

			for (int i = x; i < x+8; i++) {
				for (int j = y; j < y+8; j++) {
					if ((i + j) % 2 == 0) {
						if (a[i][j] == 'B') cnt1++;
						if (a[i][j] == 'W') cnt2++;
					}
					if ((i + j) % 2 == 1) {
						if (a[i][j] == 'W') cnt1++;
						if (a[i][j] == 'B') cnt2++;
					}
				}
			}

			if (ans > cnt1) ans = cnt1;
			if (ans > cnt2) ans = cnt2;

		}
	}

	cout << ans << '\n';
	return 0;



}

