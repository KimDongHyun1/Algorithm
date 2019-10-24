#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

bool check(int a[50], vector<int> b, int cnt, int index) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << b[i] << ' ';
		}
		cout << '\n';
		return;
	}

	if (index >= a.size() - 1) return;
	index++;
	b.pop_back();
	check(a, b, cnt + 1, index);
	b.push_back(a[index - 1]);
	b.push_back(a[index]);
	check(a, b, cnt, index);
}

int main() {

	int k;
	cin >> k;
	if (k == 0) return 0;
	int a[50];
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	vector<int> b;
	b.push_back(a[0])
	check(a, b, 0, 0);
	cout << '\n';

	return 0;
}