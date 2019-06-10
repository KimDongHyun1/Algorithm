#include <iostream>
using namespace std;
int n, m;
int a[10001];

// 답은 놀이기구의 번호를 쓰는 것이고, a[m]의 값은 놀이기구의 시간이다.

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	long long left = 0;
	long long right = 2000000000LL * 1000000LL;

	if (n <= m) {
		cout << n << '\n';
		return 0;
	}

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long begin = 0;
		long long end = m;

		for (int i = 0; i < m; i++) {
			end += mid / a[i];
		}

		begin = end;
		for (int i = 0; i < m; i++) {
			if (mid%a[i] == 0) {
				begin -= 1;
			}
		}
		begin += 1;
		if (n < begin) {
			right = mid - 1;
		}
		else if (n > end) {
			left = mid + 1;
		}
		else { // begin < n <= end;
			for (int i = 0; i < n; i++) {
				if (mid%a[i] == 0) {
					if (n == begin) {
						cout << i + 1 << '\n';
						return 0;
					}
					begin += 1;
				}
			}
		}
	}
}