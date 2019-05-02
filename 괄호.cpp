#include "pch.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

string hello(string s)
{
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') cnt++;
		else cnt--;
		if (cnt < 0) return "NO";
	}
	if (cnt == 0) return "YES";
	else return "NO";
}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		cout << hello(s) << '\n';
	}
}