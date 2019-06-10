#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;

bool check() {
	int i = n - 1;
	while ((0 < i) && (v[i] <= v[i - 1])) i--;

	if (i <= 0) return false;

	int j = n - 1;
	while (v[i - 1] >= v[j]) j--;

	swap(v[i - 1], v[j]);

	int n1 = n - 1;
	while (i < n1) {
		swap(v[i], v[n1]);
		i++;
		n1--;
	}

	return true;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
		cout << v[i] << ' ';
	}
	cout << '\n';

	while (check()) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}

}