#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
int d[12]; // N을 1,2,3의 합으로 나타내는 방법의 수

int main()
{
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	int t;
	int n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 3; i <= n; i++) {
			d[i] = d[i - 3] + d[i - 2] + d[i - 1];
		}
		cout << d[n] << '\n';
	}
	return 0;
}