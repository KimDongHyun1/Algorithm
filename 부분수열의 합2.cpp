#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;

void check(vector<int> &s, int index, int sum) {
	a.push_back(sum);

	if (index >= s.size()-1) return;
	index++;
	check(s, index, sum + s[index]);
	check(s, index, sum - s[index - 1] + s[index]);
}

int main() {
	int n;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	check(s, 0, s[0]);
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	for (int i = 0; i < a.size(); i++) {
		if (a[i] != i+1) {
			cout << i + 1 << '\n';
			return 0;
		}
		if (i == a.size() - 1) {
			cout << i + 2 << '\n';
		}
	}
	return 0;
}