#include "pch.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
stack<char> Left;
stack<char> Right;
string S;
int T;

int main()
{
	cin >> T;
	while (T--) {
		cin >> S;

		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '-') {
				if (!Left.empty()) {
					Left.pop();
				}
			}
			else if (S[i] == '>') {
				if (!Right.empty()) {
					Left.push(Right.top());
					Right.pop();
				}
			}
			else if (S[i] == '<') {
				if (!Left.empty()) {
					Right.push(Left.top());
					Left.pop();
				}
			}
			else {
				Left.push(S[i]);
			}
		}

		while (!Left.empty()) {
			Right.push(Left.top());
			Left.pop();
		}

		while (!Right.empty()) {
			cout << Right.top();
			Right.pop();
		}
		cout << '\n';
	}

	return 0;
}

