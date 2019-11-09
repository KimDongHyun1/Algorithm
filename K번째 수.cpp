#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n;
	cin >> k;

	int left = 1;
	int right = k;
	int ans = 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		int num = 0;
		for (int i = 1; i <= n; i++) {
			num += min(mid / i, n);
		}

		if (num < k) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}

	}

	cout << ans << '\n';
	return 0;
}
