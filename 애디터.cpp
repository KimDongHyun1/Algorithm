#include "pch.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	stack<char> left;
	stack<char> right;


	for (int i = 0; i < s.size(); i++) {
		left.push(s[i]);
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char key;
		cin >> key;
		if (key == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		if (key == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		if (key == 'B') {
			if (!left.empty()) {
				left.pop();
			}
		}
		if (key == 'P') {
			char x;
			cin >> x;
			left.push(x);
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
	cout << '\n';
}