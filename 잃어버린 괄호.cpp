﻿#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> num;
	vector<int> sign;

	int cur = 0;
	sign.push_back(1);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			if (s[i] == '+') {
				sign.push_back(1);
			}
			else {
				sign.push_back(-1);
			}
			num.push_back(cur);
			cur = 0;
		}
		else {
			cur = cur * 10 + (s[i] - '0');
		}
	}
	num.push_back(cur);

	int ans = 0;
	bool minus = false;

	for (int i = 0; i < num.size(); i++) {
		if (sign[i] == -1) {
			minus = true;
		}
		if (minus == false) {
			ans = ans + num[i];
		}
		else {
			ans = ans - num[i];
		}
	}
	cout << ans << '\n';
}
