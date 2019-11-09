#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[100001];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long sum = a[i];
		for (int j = i + 1; j < n; j++) {
			sum = sum + a[i];
		}
		if (ans < sum) ans = sum;
	}

	cout << ans << '\n';
	return 0;
}