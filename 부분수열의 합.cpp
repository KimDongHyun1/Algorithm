#include <iostream>
#include <vector>
using namespace std;
vector<int> b;
int ans = 0;


void check(vector<int> &a, int s, int index, int sum) {
	if (s == sum) ans++;

	if (index >= a.size() - 1) return;

	index++;
	check(a, s, index, sum + a[index]);
	check(a, s, index, sum - a[index - 1] + a[index]);
}

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	check(a, s, 0, a[0]);
	cout << ans << '\n';
}