#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
int d[1001]; // N개의 카드구매를 위한 최댓값.
int p[10001]; //
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	// 1 5 6 7 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + p[j]);
		}
	}
	cout << d[n] << '\n';
}