#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
bool check[5001];

int main() {
	queue<int> q;
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	int cnt = 0;
	while (cnt < n - 1) {
		for (int i = 1; i <= k; i++) {
			if (i == k) {
				cout << q.front() << ", ";
				q.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
		cnt++;
	}
	cout << q.front() << ">";

}