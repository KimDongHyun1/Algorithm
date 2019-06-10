#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, c;
vector<int> v;

bool check(int mid) {
	int cnt = 1;
	int left = v[0];
	for (int i = 0; i < n; i++) {
		if (v[i] - left >= mid) {
			cnt++;
			left = v[i];
		}
	}
	return cnt >= c;
}

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int left = 1;
	int right = v[n - 1] - v[0];
	int ans = left;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (check(mid)) {
			if (ans < mid) {
				ans = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans << '\n';
}