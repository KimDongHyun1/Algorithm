#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int visit[10000];
string a, b;
int cnt, temp; 

bool prime(int n) {
	for (int i = 2; i < n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

void solve() {

	visit[atoi(b.c_str())] = 1;
	queue<int> Q;
	Q.push(atoi(b.c_str()));

	cnt = 0;
	while (!Q.empty()) {
		int size = Q.size();

		while (size--) {
			int x = Q.front();
			string num = to_string(x);
			Q.pop();

			if (num == a) {
				cout << cnt << '\n';
				return;
			}

			for (int i = 1; i <= 9; i++) {
				temp = i * 1000 + (num[1] - '0') * 100 + (num[2] - '0') * 10 + (num[3] - '0');

				if (!visit[temp] && prime(temp)) {
					visit[temp] = true;
					Q.push(temp);
				}
			}
			for (int i = 0; i <= 9; i++) {
				temp = (num[0] - '0') * 1000 + i * 100 + (num[2] - '0') * 10 + (num[3] - '0');

				if (!visit[temp] && prime(temp)) {
					visit[temp] = true;
					Q.push(temp);
				}
			}
			for (int i = 0; i <= 9; i++) {
				temp = (num[0] - '0') * 1000 + (num[1] - '0') * 100 + i * 10 + (num[3] - '0');

				if (!visit[temp] && prime(temp)) {
					visit[temp] = true;
					Q.push(temp);
				}
			}
			for (int i = 0; i <= 9; i++) {
				temp = (num[0] - '0') * 1000 + (num[1] - '0') * 100 + (num[2] - '0') * 10 + i;

				if (!visit[temp] && prime(temp)) {
					visit[temp] = true;
					Q.push(temp);
				}
			}
		}
		cnt++;
	}
	
	cout << "impossible" << '\n';
}



int main()
{
	int t;
	cin >> t;

	while (t--) {
		memset(visit, 0, sizeof(visit));

		cin >> a;
		cin >> b;

		solve();
	}


}

