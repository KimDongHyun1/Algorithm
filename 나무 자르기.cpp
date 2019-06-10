#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
int a[1000000];

bool check(long long mid) {
	long long chk = 0;
	for (int i = 0; i < n; i++) {
		if (0 < a[i] - mid) {
			chk = chk + (a[i] - mid);
		}
	}
	return chk >= m;
}

int main() {
	cin >> n >> m;
	long long max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (max < a[i]) {
			max = a[i];
		}
	}

	long long left = 1;
	long long right = max;
	long long ans = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;

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
