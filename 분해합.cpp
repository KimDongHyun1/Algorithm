#include <iostream>
using namespace std;


int main()
{
	// cout << 189 % 10 << '\n'; // 9
	// cout << 189 / 10 << '\n'; // 18

	int n;
	cin >> n;
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		int sum = i;
		int mok = i;
		do {
			sum = sum + mok % 10;
			mok = mok / 10;
		} while (mok);
		if (sum == n) {
			ans = i;
			break;
		}
	}

	cout << ans << '\n';

}

