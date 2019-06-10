#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int sum = 0;
	for (char a : s) {
		sum += a - '0';
	}

	sort(s.begin(), s.end());
	if (s[0] == '0' && sum % 3 == 0) {
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}