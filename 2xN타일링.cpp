#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
int d[1001]; // 2xN크기의 직사각형을 1x2 ,2x1 타일로 채우는 방법의 수

int go(int x) {

	if (d[x] > 0) return d[x];

	d[x] = (go(x - 1) + go(x - 2)) % 10007;
	return d[x];
}

int main()
{
	d[0] = 1;
	d[1] = 1;
	int n;
	cin >> n;
	cout << go(n) << '\n';
}