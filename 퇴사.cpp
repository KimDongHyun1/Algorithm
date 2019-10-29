#include <iostream>
using namespace std;
int n;
int time[22];
int price[22];
int ans = 0;

void check(int day, int sum) {
	if (day == n + 1) {
		if (sum > ans) ans = sum;
		return;
	}
	if (day > n + 1) {
		return;
	}

	check(day + 1, sum);
	check(day + time[day], sum + price[day]);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i];
		cin >> price[i];
	}

	check(1, 0);
	cout << ans << '\n';
	return 0;
}



