#include "pch.h"
#include <iostream>
using namespace std;
int a[9][9];
int row[9][10]; // 9개의 행에서 숫자 1~9 체크하기
int col[9][10]; // 9개의 열에서 숫자 1~9 체크하기
int square[9][10]; // 9개의 네모에서 숫자 1~9 체크하기


void sdoku() {

	int r = -1;
	int c = -1;

	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			if (!a[x][y]) {
				r = x;
				c = y;
				break;
			}
		}
		if (r != -1) break;
	}

	if (r == -1) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0); // 이거 해줘야 하나만 출력하라는 문제 조건이 만족됨
	}

	for (int i = 1; i <= 9; i++) {
		if (!row[r][i] && !col[c][i] && !square[(r / 3) * 3 + (c / 3)][i]) {
			row[r][i] = col[c][i] = square[(r / 3) * 3 + (c / 3)][i] = true;
			a[r][c] = i;
			sdoku();
			row[r][i] = col[c][i] = square[(r / 3) * 3 + (c / 3)][i] = false;
			a[r][c] = 0;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a[i][j];
			// (i/3)*3 + (j/3)은 (0,0)~(2,2)까지 0~8로 숫자 만들어 주기
			row[i][a[i][j]] = col[j][a[i][j]] = square[(i / 3) * 3 + (j / 3)][a[i][j]] = true;
		}
	}

	sdoku();
	return 0;
}

