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
	while ((0 < i) && (v[i] <= v[i - 1])) i--;
	// 신기한거 : while안에 두개를 바꾸면 v[-1]도 들어갈 수 있어서 오류뜬다

	if (i <= 0) {
		cout << -1 << '\n';
		return 0;
	}

	int j = n - 1;
	while (v[i - 1] >= v[j]) j--;

	swap(v[i - 1], v[j]);

	int n1 = n - 1;
	while (i < n1) {
		swap(v[i], v[n1]);
		i++;
		n1--;
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
	return 0;
}