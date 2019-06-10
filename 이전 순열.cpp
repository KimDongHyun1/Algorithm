#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int i = n - 1;
	while ((0 < i) && (v[i - 1] < v[i])) i--;

	if (i <= 0) {
		cout << -1 << '\n';
		return 0;
	}

	int j = n - 1;
	while (v[i - 1] < v[j]) j--;

	swap(v[i - 1], v[j]);

	j = n - 1;
	while (i < j) {
		swap(v[i], v[j]);
		i++;
		j--;
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
	return 0;
}