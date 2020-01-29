#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
int t, x, watch, ans;
deque<int> D[10];
string s;

//시계
void go(int n) {
	D[n].push_front(D[n].back());
	D[n].pop_back();
}

void back(int n) {
	D[n].push_back(D[n].front());
	D[n].pop_front();
}

int main()
{
	for (int i = 1; i <= 4; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			D[i].push_back(s[j] - '0');
		}
	}

	cin >> t;
	while (t--) {
		cin >> x >> watch;

		if (x == 1) {
			if (D[1][2] != D[2][6]) {
				if (D[2][2] != D[3][6]) {
					if (D[3][2] != D[4][6]) {
						if (watch == 1) back(4);
						else go(4);
					}
					if (watch == 1) go(3);
					else back(3);
				}
				if (watch == 1) back(2);
				else go(2);
			}
			if (watch == 1) go(1);
			else back(1);
		}

		if (x == 2) {
			if (D[1][2] != D[2][6]) {
				if (watch == 1) back(1);
				else go(1);
			}
			if (D[2][2] != D[3][6]) {
				if (D[3][2] != D[4][6]) {
					if (watch == 1) go(4);
					else back(4);
				}
				if (watch == 1) back(3);
				else go(3);
			}
			if (watch == 1) go(2);
			else back(2);
		}

		if (x == 3) {
			if (D[2][2] != D[3][6]) {
				if (D[1][2] != D[2][6]) {
					if (watch == 1) go(1);
					else back(1);
				}
				if (watch == 1) back(2);
				else go(2);
			}
			if (D[3][2] != D[4][6]) {
				if (watch == 1) back(4);
				else go(4);
			}
			if (watch == 1) go(3);
			else back(3);
		}

		if (x == 4) {
			if (D[3][2] != D[4][6]) {
				if (D[2][2] != D[3][6]) {
					if (D[1][2] != D[2][6]) {
						if (watch == 1) back(1);
						else go(1);
					}
					if (watch == 1) go(2);
					else back(2);
				}
				if (watch == 1) back(3);
				else go(3);
			}
			if (watch == 1) go(4);
			else back(4);
		}

	}

	if (D[1][0]) ans += 1;
	if (D[2][0]) ans += 2;
	if (D[3][0]) ans += 4;
	if (D[4][0]) ans += 8;

	cout << ans << '\n';
}
