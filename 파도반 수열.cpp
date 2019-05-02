#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
long long d[101];

int main()
{
	int t;
	cin >> t;
	int n;
	d[1] = d[2] = d[3] = 1;
	d[4] = d[5] = 2;

	while (t--) {
		cin >> n;



		for (int i = 6; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 5];
		}

		cout << d[n] << '\n';
	}
}