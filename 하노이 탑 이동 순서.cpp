#include <iostream>
#include <vector>
using namespace std;
int n;
vector<pair<int, int>> v;
int cnt = 0;


void hanoi(int n, int from, int to) {
	if (n == 0) return;

	cnt++;
	hanoi(n - 1, from, 6 - from - to);
	v.push_back(make_pair(from, to));
	hanoi(n - 1, 6 - from - to, to);
}

int main() {
	cin >> n;

	hanoi(n, 1, 3);

	cout << cnt << '\n';

	for (auto &x : v) {
		cout << x.first << ' ' << x.second << '\n';
	}

}