#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> num(n);
	vector<int> sign;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		int cnt = 0;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			sign.push_back(i);
		}
	}

	int sum = num[0];
	for (int i = 0; i < sign.size(); i++) {
		if (sign[i] == 0) sum = sum + num[i + 1];
		if (sign[i] == 1) sum = sum - num[i + 1];
		if (sign[i] == 2) sum = sum * num[i + 1];
		if (sign[i] == 3) sum = sum / num[i + 1];
	}

	int min = sum;
	int max = sum;

	do {
		int sum = num[0];

		for (int i = 0; i < sign.size(); i++) {
			if (sign[i] == 0) sum = sum + num[i + 1];
			if (sign[i] == 1) sum = sum - num[i + 1];
			if (sign[i] == 2) sum = sum * num[i + 1];
			if (sign[i] == 3) sum = sum / num[i + 1];
		}

		if (max < sum) max = sum;
		if (min > sum) min = sum;

	} while (next_permutation(sign.begin(), sign.end()));

	cout << max << '\n' << min << '\n';
}
