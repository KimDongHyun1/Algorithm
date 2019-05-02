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
	for (int i = 1; i <= n; i++) {
		d[i] = i;
		for (int j = 1; j*j <= i; j++) {
			if (d[i] > d[i - j * j] + 1) {
				d[i] = d[i - j * j] + 1;
			}
		}
	}
	cout << d[n] << '\n';
}