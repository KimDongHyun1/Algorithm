#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;

void rec(vector<int> &a, int index, int sum, int s) {
	if (sum == s) {
		cnt++;
	}

	if (index >= a.size()-1 ) return;
	rec(a, index + 1, sum - a[index] + a[index + 1], s);
	rec(a, index + 1, sum + a[index + 1], s);
}

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	rec(a, 0, a[0], s);

	cout << cnt << '\n';
}