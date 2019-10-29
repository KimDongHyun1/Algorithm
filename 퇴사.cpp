#include "pch.h"
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
	} // 마지막 날짜의 time이 1이라면 그 날 까지 더해야 함으로 n+1로 두었음
	if (day > n + 1) {
		return;
	} // time이 일정 날짜를 넘어가면 none

	check(day + 1, sum); // 만약 7일까지이고 6일날 1000000000이 나왔을 때 7일까지 7일을 건너려고 and 
						 // 2,3,4일.... 부터 시작하기위해
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



