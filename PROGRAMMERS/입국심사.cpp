#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());

	long long ans = (long long) times[times.size() - 1] * n;
	long long left = 1;
	long long right = (long long) times[times.size() - 1] * n;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;

		for (int i = 0; i < times.size(); i++) {
			sum += mid / times[i];
		}

		if (sum >= n) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}


	return ans;
}


int main()
{
	int n = 6;
	vector<int> times = { 7,10 };
	// return 28;

	sort(times.begin(), times.end());
	
	cout << solution(n, times) << '\n';

	/*long long left = 1;
	long long right = times[times.size() - 1] * n;
	long long ans = times[times.size() - 1] * n;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;

		for (int i = 0; i < times.size(); i++) {
			sum += mid / times[i];
		}
		
		if (sum >= n) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans << '\n';
	return 0;*/

	
}
