#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
int t, n, m, x , cnt;

int main() {
	cin >> t;

	while (t--) {
		cin >> n >> m;
		queue<pair<int, int>> Q;
		priority_queue<int> PQ;
		for (int i = 0; i < n; i++) {
			cin >> x;
			Q.push(make_pair(i, x));
			PQ.push(x);
		}

		cnt = 1;
		while (true) {
			int index = Q.front().first;
			int value = Q.front().second;

			if (m == index) {
				if (PQ.top() == value) {
					break;
				}

				Q.pop();
				Q.push(make_pair(index, value));
			}
			else {
				if (PQ.top() == value) {
					Q.pop();
					PQ.pop();
					cnt++;
				}
				else {
					Q.pop();
					Q.push(make_pair(index, value));
				}
			}

		}

		cout << cnt << '\n';
	}

	return 0;
	
}