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

int main()
{
	char a[100001];
	string s;
	cin >> s;
	int ans = 0, cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		a[i] = s[i];
	}
	for (int i = 0; i < s.size(); i++) {
		if (a[i] == '(') cnt++;
		else {
			if (a[i - 1] == '(') {
				cnt--;
				ans += cnt;
			}
			else {
				cnt--;
				ans += 1;
			}
		}
	}
	cout << ans << '\n';
}