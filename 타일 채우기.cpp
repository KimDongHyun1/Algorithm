#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
int d[100001]; // N을 그 합으로써 표현할 수 있는 제곱항의 최소 갯수.
// 11 = 5 , 3

int main()
{
	int n;
	cin >> n;
	d[0] = 1;

	for (int i = 2; i <= n; i++) {
		d[i] = 0;
		for (int j = 2; j <= i; j += 2) {
			if (j == 2) d[i] = d[i] + 3 * d[i - 2];
			else d[i] = d[i] + 2 * d[i - j];
		}
	}

	cout << d[n] << '\n';
}